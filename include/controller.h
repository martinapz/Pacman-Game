#pragma once

#ifndef FINAL_PROJECT_CONTROLLER_H
#define FINAL_PROJECT_CONTROLLER_H

#include "game_instructions.h"
#include "visualizer/sketchpad.h"
#include "visualizer/features.h"
#include "elements/ghost.h"
#include "elements/pacman.h"
#include <elements/empty.h>
#include <elements/wall.h>
#include <elements/immunity.h>
#include <elements/coin.h>
#include <elements/ghost_container.h>

namespace finalproject {
    /**
     * Game struct holds the features that make up the Pacman game.
     */
    struct Game {
        visualizer::Sketchpad sketchpad_ = visualizer::Sketchpad(glm::vec2(Configuration::WINDOW_MARGIN,
             Configuration::WINDOW_MARGIN), Configuration::GRID_SIZE, Configuration::SKETCHPAD_SIZE - 2 * Configuration::WINDOW_MARGIN,0);
        std::vector<Ghost> ghosts_ = std::vector<Ghost>();
        Pacman pacman_;
        size_t score_ = 0;
        visualizer::Features features_;
        Status game_status = Status::NOT_STARTED;
        int number_of_coins_ = 0;
        size_t level_ = 1;
        size_t lives_ = Configuration::NUMBER_OF_LIVES;
        bool immunity_ = false;
    };

    /**
     * Controller class handles the logic for movements within the Pacman game.
     */
    class Controller {
    public:

        /**
         * Default constructor.
         */
        Controller() = default;

        /**
         * Sets up the game by initializing each pixel of the board.
         */
        void setUpGame();

        /**
         * Updates the positions based on move at each time frame.
         */
        void update();

        /**
         * Draws the sketchpad, Pacman, and ghosts.
         */
        void draw();

        /**
         * Processes the direction that the user wants to move to and decides if it is a valid move.
         * @param direction where the element wants to move
         */
        void processMove(Direction direction);

        /**
         * Processes the action.
         * @param action that is being processed
         */
        void processAction(Action action);

    private:
        /**
         * Determines the new point given the direction that the element wants to move.
         * @param direction that element wants to move in
         * @param element that will be moved
         * @return point the element can move to
         */
        Point determineNewPoint(Direction direction, DynamicElement* element);

        /**
         * Checks if pacman can move to possible new point, and if it can, updates the pacman position.
         */
        void movePacman();

        /**
         * Checks if ghost can move to possible new point, and if it can, updates the ghost position.
         * @param ghost that will possibly be moved
         */
        void moveGhost(Ghost *ghost);

        /**
         * Handles logic for ghost movement when it is inside of the ghost container.
         * @param ghost that will possibly be moved
         */
        void moveInsideGhost(Ghost *ghost);

        /**
         * Handles logic for ghost movement when it is outside of the ghost container.
         * @param ghost that will possibly be moved
         */
        void moveOutsideGhost(Ghost *ghost);

        /**
         * Keeps track of how long pacman has immunity when it eats the immunity tiles.
         */
        void updateImmunityStatus();

        /**
         * Handles logic for when pacman lands on the same tile as a ghost.
         */
        bool lifeLost();

        /**
         * Draws the pacman and the ghosts.
         */
        void drawDynamicComponents();

        /**
         * Draws the starting image of the game.
         */
        void drawGameNotStarted();

        /**
         * Draws the ending image of the game.
         */
        void drawGameOver();

        /**
         * Draws the winning image of the game.
         */
        void drawGameWon();

        /**
         * Takes in an image and converts it into a texture.
         * @param relativePath the image that will be converted
         * @return texture of that image
         */
        ci::gl::Texture2dRef Controller::setUpLoadImages(const cinder::fs::path &relativePath);

        // Pointers to static elements
        std::shared_ptr<Empty> empty_ = std::shared_ptr<Empty>(new Empty());
        std::shared_ptr<Wall> wall_ = std::shared_ptr<Wall>(new Wall());
        std::shared_ptr<Immunity> immunity_ = std::shared_ptr<Immunity>(new Immunity());
        std::shared_ptr<Coin> coin_ = std::shared_ptr<Coin>(new Coin());
        std::shared_ptr<GhostContainer> ghost_container_ = std::shared_ptr<GhostContainer>(new GhostContainer());
        std::shared_ptr<GhostContainer> center_ghost_container_ = std::shared_ptr<GhostContainer>(new GhostContainer());

        Configuration config_;
        Game game_;

        std::chrono::steady_clock::time_point start_time_;
        std::chrono::steady_clock::time_point immunity_start_time_;

        //Images for pacman and ghosts
        ci::gl::Texture2dRef starting_image_ = setUpLoadImages("pacman_starting_image.jpg");
        ci::gl::Texture2dRef winning_image_ = setUpLoadImages("winning_image.png");
        ci::gl::Texture2dRef ending_image_ = setUpLoadImages("game_over.png");
        ci::gl::Texture2dRef ghost1_texture_ = setUpLoadImages("ghost1.png");
        ci::gl::Texture2dRef ghost2_texture_ = setUpLoadImages("ghost2.png");
        ci::gl::Texture2dRef pacman_texture_ = setUpLoadImages("pacmanR.png");
        ci::gl::Texture2dRef immunity_ghost_texture_ = setUpLoadImages("immunity.png");
    };

} //namespace finalproject

#endif //FINAL_PROJECT_CONTROLLER_H
