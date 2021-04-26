#include "controller.h"
#include "types.h"
#include <elements/wall.h>
#include <elements/coin.h>
#include <elements/immunity.h>
#include <elements/door.h>
#include <cmath>

using namespace std;

namespace finalproject {

    void Controller::setUpGame() {
        shared_ptr<Wall> wall(new Wall());
        shared_ptr<Immunity> immunity(new Immunity());
        shared_ptr<Coin> coin(new Coin());
        shared_ptr<Door> door(new Door());
        vector<vector<std::shared_ptr<StaticElement>>> static_elements = vector<vector<std::shared_ptr<StaticElement>>>(
                Configuration::GRID_SIZE, vector<std::shared_ptr<StaticElement>>(Configuration::GRID_SIZE));
        ifstream in(config_.LEVEL_DATA_FILE);
        if (!in.fail()) {
            unsigned i = 0;
            for (std::string line; getline(in, line);) {
                for (unsigned j = 0; j < config_.GRID_SIZE; j++) {
                    switch (line.at(j)) {
                        case 'P':
                            static_elements[j][i] = empty_;
                            game_.pacman_ = Pacman(j, i);
                            break;
                        case 'G':
                            static_elements[j][i] = empty_;
                            game_.ghosts_.push_back(Ghost(j, i));
                            break;
                        case 'T':
                            static_elements[j][i] = door;
                            break;
                        case '#':
                            static_elements[j][i] = wall;
                            break;
                        case '-':
                            static_elements[j][i] = coin;
                            break;
                        case 'C':
                            static_elements[j][i] = immunity;
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

    void Controller::draw() {
        cinder::gl::clear();
        game_.sketchpad_.draw();
        game_.pacman_.draw();
        game_.features_.draw();

        string string = "SCORE: " + to_string(game_.score_);
        ci::gl::drawString(string , vec2(1050, 70), "white",ci::Font("", 30));


        for (vector<Ghost>::iterator ghost = game_.ghosts_.begin(); ghost != game_.ghosts_.end(); ++ghost) {
            ghost->draw();
        }
    }

    void Controller::update() {
        /*
        // Update ghosts position to move to position closest to pacman
        for (Ghost ghost : game_.ghosts_) {
            calculateNewGhostPosition(ghost);
        }
        */

        //Determine next pacman position
        Point newPoint = determineNewPoint(game_.pacman_.getDirection());
        //Check is new point is a wall
        shared_ptr<StaticElement> element = game_.sketchpad_.GetStaticElements()[newPoint.getX()][newPoint.getY()];
        if (!dynamic_pointer_cast<Wall>(element)) { //If new point is not wall, change position
            game_.pacman_.setPosition(newPoint.getX(), newPoint.getY());
            if (dynamic_pointer_cast<Coin>(element)) {  //If new point is a coin, increment score and set element to empty
                game_.sketchpad_.GetStaticElements()[newPoint.getX()][newPoint.getY()] = empty_;
                game_.score_ += 10;
            }
        }

        /*
        // If pacman is on same position as ghost then game over
        for(Ghost ghost : game_.ghosts_) {
            if (newPoint.getX() == ghost.getPosition().getX() && newPoint.getY() == ghost.getPosition().getY()) {
                //Game is over
            }
        }
         */

        //Check if pacman is on an static elements
        //shared_ptr<StaticElement> element = game_.sketchpad_.GetStaticElements()[newX][game_.pacman_.getPosition().getY()];
        //If it is a wall, the position does not change.

        /*
        if (auto wall = dynamic_pointer_cast<Wall>(element)) {

        } else if (auto dot = dynamic_pointer_cast<Dot>(element)) { // If pacman is on Dot increase score and set position to empty
            game_.sketchpad_.GetStaticElements()[newX][game_.pacman_.getPosition().getY()] == empty_;
        } else if (auto coin = dynamic_pointer_cast<Coin>(element)) { //If pacman is on Coin increase score and set position to empty
            game_.sketchpad_.GetStaticElements()[newX][game_.pacman_.getPosition().getY()] == empty_;
        }
         */
    }



    void Controller::processMove(Direction direction) {
        // Get the destination based on the user's selected direction
        Point newPoint = determineNewPoint(direction);
        //Check if the pacman can enter the destination tile
        shared_ptr<StaticElement> element = game_.sketchpad_.GetStaticElements()[newPoint.getX()][newPoint.getY()];
        if (!dynamic_pointer_cast<Wall>(element)) {
           game_.pacman_.setDirection(direction);
        }
    }


    void Controller::processAction(Action action) {

    }

    Point Controller::determineNewPoint(Direction direction) {
        size_t newX;
        size_t newY;
        switch (direction) {
            case Direction::RIGHT :
                newX = game_.pacman_.getPosition().getX() + 1 <= Configuration::GRID_SIZE ?
                       game_.pacman_.getPosition().getX() + 1 : game_.pacman_.getPosition().getX();
                newY = game_.pacman_.getPosition().getY();
                break;
            case Direction::LEFT :
                newX = game_.pacman_.getPosition().getX() - 1 >= 0 ?
                       game_.pacman_.getPosition().getX() - 1 : game_.pacman_.getPosition().getX();
                newY = game_.pacman_.getPosition().getY();
                break;
            case Direction::DOWN :
                newY = game_.pacman_.getPosition().getY() + 1 <= Configuration::GRID_SIZE ?
                       game_.pacman_.getPosition().getY() + 1 : game_.pacman_.getPosition().getY();
                newX = game_.pacman_.getPosition().getX();
                break;
            case Direction::UP :
                newY = game_.pacman_.getPosition().getY() - 1 <= Configuration::GRID_SIZE ?
                       game_.pacman_.getPosition().getY() - 1 : game_.pacman_.getPosition().getY();
                newX = game_.pacman_.getPosition().getX();
                break;
            default :
                break;
        }
        Point newPoint(newX, newY);
        return newPoint;
    }

    double Controller::distanceToPacman(Point a, Point b) {
        double x = (a.getX() - b.getX()) * (a.getX() - b.getX());
        double y = (a.getY() - b.getY()) * (a.getY() - b.getY());
        return abs(std::sqrt(x + y));
    }

    void Controller::calculateNewGhostPosition(Ghost ghost) {
        //TODO add to see if where they want to move is a wall
        Point new_position;
        //Finds distance of ghost from pacman when moving up
        Point move_up = Point(ghost.getPosition().getX(), ghost.getPosition().getY() + 1);
        double distance = distanceToPacman(ghost.getPosition(), move_up);

        Point move_right = Point(ghost.getPosition().getX() + 1, ghost.getPosition().getY());
        if (distanceToPacman(move_right, game_.pacman_.getPosition()) < distance) {
            distance = distanceToPacman(move_right, game_.pacman_.getPosition());
            new_position = move_right;
        }

        Point move_left = Point(ghost.getPosition().getX() - 1, ghost.getPosition().getY());
        if (distanceToPacman(move_left, game_.pacman_.getPosition()) < distance) {
            distance = distanceToPacman(move_left, game_.pacman_.getPosition());
            new_position = move_left;
        }

        Point move_down = Point(ghost.getPosition().getX(), ghost.getPosition().getY() - 1);
        if (distanceToPacman(move_down, game_.pacman_.getPosition()) < distance) {
            distance = distanceToPacman(move_down, game_.pacman_.getPosition());
            new_position = move_down;
        }
        ghost.setPosition(new_position.getX(), new_position.getY());
    }
}