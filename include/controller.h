#pragma once

#ifndef FINAL_PROJECT_CONTROLLER_H
#define FINAL_PROJECT_CONTROLLER_H

#include "game_instructions.h"
#include "visualizer/sketchpad.h"
#include "visualizer/features.h"
#include "elements/ghost.h"
#include "elements/pacman.h"
#include <elements/empty.h>
#include <elements/door.h>

using namespace std;

namespace finalproject {

    /**
     * Game struct
     */
    struct Game {
        visualizer::Sketchpad sketchpad_ = visualizer::Sketchpad(glm::vec2(Configuration::WINDOW_MARGIN,
             Configuration::WINDOW_MARGIN), Configuration::GRID_SIZE, Configuration::SKETCHPAD_SIZE - 2 * Configuration::WINDOW_MARGIN,0);
        vector<Ghost> ghosts_ = vector<Ghost>();
        Pacman pacman_;
        size_t score_ = 0;
        visualizer::Features features_;
        Status game_status = Status::NOT_STARTED;
        int number_of_coins_ = 0;
    };

    /**
     * Controller class handles the logic for movements within the Pacman game.
     */
    class Controller {
    public:
        /**
        * Default constructor
        */
        Controller() = default;

        /**
        * Sets up the game by initializing each pixel of the board
        */
        void setUpGame();

        /**
        * Updates the positions based on move at each time frame
        */
        void update();

        /**
        * Draws the sketchpad, Pacman, and ghosts
        */
        void draw();

        /**
        * Processes the direction that the user wants to move to and decides if it is a valid move
        */
        void processMove(Direction direction);

        /**
        * Processes the action
        */
        void processAction(Action action);

    private:
        ci::gl::Texture2dRef Controller::setUpLoadImages(const cinder::fs::path &relativePath);
        void calculateNewGhostPosition(Ghost ghost);
        Point determineNewPoint(Direction direction);
        double distanceToPacman(Point a, Point b);

        Configuration config_;
        Game game_;
        std::shared_ptr<Empty> empty_ = shared_ptr<Empty>(new Empty());
        std::shared_ptr<Door> door_ = shared_ptr<Door>(new Door());
        chrono::steady_clock::time_point start_time_;
        size_t increment_score = 10;
        ci::gl::Texture2dRef starting_image_;
    };

}
#endif //FINAL_PROJECT_CONTROLLER_H
