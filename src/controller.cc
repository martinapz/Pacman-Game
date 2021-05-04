#include "controller.h"
#include "game_instructions.h"
#include <cmath>
#include <chrono>
#include <pacman_app.h>

using namespace std;

namespace finalproject {

    void Controller::setUpGame() {
        // Clear ghosts vector and number of coins, and close door
        game_.number_of_coins_ = 0;
        game_.ghosts_.clear();
        center_ghost_container_->setIsOpen(false);

        // Create vector of static elements and initialize it
        static_elements_vector static_elements = static_elements_vector(Configuration::GRID_SIZE,
                                              vector<std::shared_ptr<StaticElement>>(Configuration::GRID_SIZE));

        // Load level board file & process it to setup the game
        ifstream in(config_.LEVEL_DATA_FILE + std::to_string(game_.level_) + ".txt");
        if (!in.fail()) {
            size_t i = 0;
            size_t number_of_ghosts = 0;
            for (std::string line; getline(in, line);) {
                for (unsigned j = 0; j < config_.GRID_SIZE; j++) {
                    switch (line.at(j)) {
                        case 'P':
                            static_elements[j][i] = empty_;
                            game_.pacman_ = Pacman(j, i, pacman_texture_);
                            break;
                        case 'G':
                            static_elements[j][i] = ghost_container_;
                            number_of_ghosts++;
                            game_.ghosts_.push_back(Ghost(j, i, ghost1_texture_, immunity_ghost_texture_));
                            break;
                        case 'D':
                            static_elements[j][i] = center_ghost_container_;
                            number_of_ghosts++;
                            game_.ghosts_.push_back(Ghost(j, i, ghost2_texture_, immunity_ghost_texture_));
                            break;
                        case '#':
                            static_elements[j][i] = wall_;
                            break;
                        case '-':
                            static_elements[j][i] = coin_;
                            //Initializing the number of coins on the board.
                            game_.number_of_coins_++;
                            break;
                        case 'C':
                            static_elements[j][i] = immunity_;
                            break;
                        default:
                            static_elements[j][i] = empty_;
                            break;
                    }
                }
                i++;
            }
            game_.sketchpad_.SetStaticElements(static_elements);
        } else {
            throw invalid_argument("Level board file not found");
        }
    }

    void Controller::update() {
        if (game_.game_status == ACTIVE) {
            //Update the elapsed time
            auto game_elapsed_time_ = std::chrono::duration_cast<std::chrono::seconds>(
                    std::chrono::steady_clock::now() - start_time_).count();

            if (game_elapsed_time_ > 2) {
                //Open the ghost container
                center_ghost_container_ ->setIsOpen(true);
            }

            //Moves the pacman
            movePacman();

            //After moving pacman, check if there are any coins left in level
            if (game_.number_of_coins_ == 0) {
                game_.level_++;
                game_.game_status = game_.level_ > Configuration::NUMBER_OF_LEVELS ? Status::GAME_WINNER : Status::LEVEL_WON;
            } else {
                // Check life lost after pacman moves. Checks for special case when pacman and
                //ghost switch positions.
                if (lifeLost()) {
                    return;
                }

                // If immunity is active check if it need to be deactivated
                if (game_.immunity_) {
                    updateImmunityStatus();
                }

                // Move each ghost
                if (center_ghost_container_ ->isOpen()) {
                    for (Ghost &ghost : game_.ghosts_) {
                        moveGhost(&ghost);
                    }
                }

                // Check life lost after ghosts moved
                if (lifeLost()) {
                    return;
                }
            }
        } else if (game_.game_status == LEVEL_WON) {
            // Loads and sets up game for new level
            setUpGame();
        }
    }

    void Controller::draw() {
        cinder::gl::clear();
        switch (game_.game_status) {
            case NOT_STARTED :
                drawGameNotStarted();
                break;
            case ACTIVE :
            case PAUSED :
            case LEVEL_WON :
            case LIFE_LOST :
            case IN_BETWEEN_LEVELS :
                //Draws sketchpad and updated score
                game_.sketchpad_.draw();
                game_.features_.draw(game_.score_, game_.level_, game_.game_status, game_.lives_);
                //Draws dynamic components of the game, including the pacman and ghost.
                drawDynamicComponents();
                break;
            case OVER :
                drawGameOver();
                break;
            case GAME_WINNER :
                drawGameWon();
        }
    }

    void Controller::drawGameWon() {
        glm::vec2 pixel_top_left = glm::vec2(0, 0);
        glm::vec2 pixel_bottom_right = glm::vec2(Configuration::WINDOWS_SIZE_X, Configuration::WINDOWS_SIZE_Y);
        ci::Area area = ci::Area(pixel_top_left, pixel_bottom_right);
        ci::gl::draw(winning_image_, area);
    }
    void Controller::drawGameNotStarted() {
        //If game has not started yet, draw intro picture
        glm::vec2 pixel_top_left = glm::vec2(0, 0);
        glm::vec2 pixel_bottom_right = glm::vec2(Configuration::WINDOWS_SIZE_X, Configuration::WINDOWS_SIZE_Y);
        ci::Area area = ci::Area(pixel_top_left, pixel_bottom_right);
        ci::gl::draw(starting_image_, area);
    }

    void Controller::drawGameOver() {
        //DRAW LOST IMAGE
        glm::vec2 pixel_top_left = glm::vec2(0, 0);
        glm::vec2 pixel_bottom_right = glm::vec2(Configuration::WINDOWS_SIZE_X, Configuration::WINDOWS_SIZE_Y);
        ci::Area area = ci::Area(pixel_top_left, pixel_bottom_right);
        ci::gl::draw(ending_image_, area);
    }

    void Controller::drawDynamicComponents() {
        // Draw pacman
        game_.pacman_.draw();
        // Draw ghosts based on the immunity status
        for (vector<Ghost>::iterator ghost = game_.ghosts_.begin(); ghost != game_.ghosts_.end(); ++ghost) {
            if (game_.immunity_) {
                ghost->drawInactive();
            } else {
                ghost->draw();
            }
        }

    }

    bool Controller::lifeLost() {
        // If immunity is not active and pacman ends up on same position as ghost then life is lost
        if (!game_.immunity_) {
            for (Ghost &ghost : game_.ghosts_) {
                if (game_.pacman_.getPosition().getX() == ghost.getPosition().getX() &&
                    game_.pacman_.getPosition().getY() == ghost.getPosition().getY()) {
                    game_.lives_--;
                    game_.game_status = (game_.lives_ == 0) ? Status::OVER : Status::LIFE_LOST;
                    // Game is over or a life was lost so nothing else needs to be updated
                    return true;
                }
            }
        }
        return false;
    }

    void Controller::updateImmunityStatus() {
        auto immunity_elapsed_time = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::steady_clock::now()
                - immunity_start_time_).count();
        if (immunity_elapsed_time > Configuration::SECONDS_TO_RELEASE_GHOSTS) {
            game_.immunity_ = false;
        }
    }

    void Controller::movePacman() {
        //Determine next pacman position
        Point pacmanNewPoint = determineNewPoint(game_.pacman_.getDirection(), &game_.pacman_);

        shared_ptr<StaticElement> element = game_.sketchpad_.GetStaticElements()[pacmanNewPoint.getX()][pacmanNewPoint.getY()];
        //Check is new point is a wall
        if (!dynamic_pointer_cast<Wall>(element)) {
            game_.pacman_.setPosition(pacmanNewPoint.getX(), pacmanNewPoint.getY());
            if (dynamic_pointer_cast<Coin>(element)) {  //If new point is a coin, increment score and set element to empty
                game_.sketchpad_.GetStaticElements()[pacmanNewPoint.getX()][pacmanNewPoint.getY()] = empty_;
                game_.score_ += Configuration::COIN_VALUE;
                game_.number_of_coins_--;
            } else if (dynamic_pointer_cast<Immunity>(element)) {
                game_.sketchpad_.GetStaticElements()[pacmanNewPoint.getX()][pacmanNewPoint.getY()] = empty_;
                game_.immunity_ = true;
                immunity_start_time_ = chrono::steady_clock::now();
            }
        }
    }

    void Controller::moveOutsideGhost(Ghost *ghost) {
        //Determine next ghost position
        Point ghostNewPoint = determineNewPoint(ghost->getDirection(), ghost);
        shared_ptr<StaticElement> element = game_.sketchpad_.GetStaticElements()[ghostNewPoint.getX()][ghostNewPoint.getY()];
        if (!dynamic_pointer_cast<Wall>(element) && !(dynamic_pointer_cast<GhostContainer>(element))) {
            ghost->setPosition(ghostNewPoint.getX(), ghostNewPoint.getY());
        } else {
            Direction randomDirection = Direction(std::rand() % 4);
            Point newPoint = determineNewPoint(randomDirection, ghost);
            shared_ptr<StaticElement> newElement = game_.sketchpad_.GetStaticElements()[newPoint.getX()][newPoint.getY()];
            if (!dynamic_pointer_cast<Wall>(newElement) && !(dynamic_pointer_cast<GhostContainer>(newElement))) {
                ghost->setDirection(randomDirection);
                ghost->setPosition(newPoint.getX(),newPoint.getY());
            } else {
                moveOutsideGhost(ghost);
            }
        }
    }

    void Controller::moveGhost(Ghost *ghost) {
        // Check if ghost is inside or outside a ghost container
        shared_ptr<StaticElement> element = game_.sketchpad_.GetStaticElements()[ghost->getPosition().getX()][ghost->getPosition().getY()];
        if (dynamic_pointer_cast<GhostContainer>(element)) {
            // Ghost is in a GhostContainer location so move it out or to the center
            moveInsideGhost(ghost);
        } else {
            // Ghost is outside a GhostContainer location so move it randomly to a new position
            moveOutsideGhost(ghost);
        }
    }

    void Controller::moveInsideGhost(Ghost *ghost) {
        switch (ghost->getPosition().getX()) {
            case Configuration::GRID_CENTER_X:
                // Ghost is in the GhostContainer with the door so it can go out
                ghost->setDirection(Direction::UP);
                ghost->setPosition(ghost->getPosition().getX(),ghost->getPosition().getY()-1);
                break;
            case Configuration::GRID_CENTER_X - 1:
                ghost->setDirection(Direction::RIGHT);
                ghost->setPosition(ghost->getPosition().getX()+ 1,ghost->getPosition().getY());
                break;
            case Configuration::GRID_CENTER_X + 1:
                ghost->setDirection(Direction::LEFT);
                ghost->setPosition(ghost->getPosition().getX()- 1,ghost->getPosition().getY());
                break;
        }
    }

    void Controller::processMove(Direction direction) {
        // Get the destination based on the user's selected direction
        Point newPoint = determineNewPoint(direction, &game_.pacman_);
        //Check if the pacman can enter the destination tile
        shared_ptr<StaticElement> element = game_.sketchpad_.GetStaticElements()[newPoint.getX()][newPoint.getY()];
        if (!dynamic_pointer_cast<Wall>(element) && !(dynamic_pointer_cast<GhostContainer>(element))) {
           game_.pacman_.setDirection(direction);
        }
    }

    void Controller::processAction(Action action) {
        if (game_.game_status != OVER) {
            switch (action) {
                case Action::START :
                    game_.game_status = Status::ACTIVE;
                    start_time_ = chrono::steady_clock::now();
                    break;
                case Action::PAUSE :
                    game_.game_status = Status::PAUSED;
                    break;
                case Action::EXIT :
                    game_.game_status = Status::OVER;
                    break;
                case Action::START_LEVEL :
                    setUpGame();
                    game_.game_status = Status::IN_BETWEEN_LEVELS;
                    start_time_ = chrono::steady_clock::now();
                    break;
                default :
                    break;
            }
        }
    }

    Point Controller::determineNewPoint(Direction direction, DynamicElement* element) {
        size_t newX;
        size_t newY;
        switch (direction) {
            case Direction::RIGHT :
                newX = element -> getPosition().getX() + 1 <= Configuration::GRID_SIZE ?
                       element -> getPosition().getX() + 1 : element -> getPosition().getX();
                newY = element -> getPosition().getY();
                break;
            case Direction::LEFT :
                newX = element -> getPosition().getX() - 1 >= 0 ?
                       element -> getPosition().getX() - 1 : element -> getPosition().getX();
                newY = element -> getPosition().getY();
                break;
            case Direction::DOWN :
                newY = element -> getPosition().getY() + 1 <= Configuration::GRID_SIZE ?
                       element -> getPosition().getY() + 1 : element -> getPosition().getY();
                newX = element -> getPosition().getX();
                break;
            case Direction::UP :
                newY = element -> getPosition().getY() - 1 <= Configuration::GRID_SIZE ?
                       element -> getPosition().getY() - 1 : element -> getPosition().getY();
                newX = element -> getPosition().getX();
                break;
            default :
                break;
        }
        Point newPoint(newX, newY);
        return newPoint;
    }

    ci::gl::Texture2dRef Controller::setUpLoadImages(const cinder::fs::path &relativePath ) {
        // Load images - https://libcinder.org/docs/guides/opengl/part4.html
        auto gImg1 = loadImage( ci::app::loadAsset( relativePath) );
        ci::gl::Texture2dRef texture = ci::gl::Texture2d::create(gImg1);
        return texture;
    }
}