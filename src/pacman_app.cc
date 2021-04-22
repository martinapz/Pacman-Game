#include "pacman_app.h"
#include "cinder/Log.h"
#include "types.h"

namespace finalproject {

    PacmanApp::PacmanApp() {}

    void PacmanApp::setup() {
        game_ = setUpGame();
     }

    void PacmanApp::update() {
    }

    void PacmanApp::draw() {
        game_.sketchpad_.Draw();
    }

    void PacmanApp::keyDown(cinder::app::KeyEvent event) {
    }

    void PacmanApp::setGame(Game game) {
        game_ = game;
    }

    Game PacmanApp::setUpGame() {
        Game game;
        std::ifstream in(config_.LEVEL_DATA_FILE);
        if (!in.fail()) {
            unsigned i = 0;
            for (std::string line; getline(in, line);) {
                for (unsigned j = 0; j < config_.GRID_SIZE; j++) {
                    switch (line.at(j)) {
                        case 'P':
                            game_.pixels_[i][j] = PACMAN;
                            break;
                        case '#':
                            game_.pixels_[i][j] = WALL;
                            break;
                        case '-':
                            game_.pixels_[i][j] = DOT;
                            break;
                        case 'C':
                            game_.pixels_[i][j] = COIN;
                            break;
                        case 'G':
                            game_.pixels_[i][j] = GHOST;
                            break;
                        case 'T':
                            game_.pixels_[i][j] = DOOR;
                            break;
                        default: // EMPTY
                            game_.pixels_[i][j] = EMPTY;
                            break;
                    }
                }
                i++;
            }
            game.sketchpad_.SetElements(game_.pixels_);
            return game;
        } else {
            throw invalid_argument("Level board file not found");
        }
    }
}  // namespace finalproject
