#pragma once

#ifndef FINAL_PROJECT_CONTROLLER_H
#define FINAL_PROJECT_CONTROLLER_H

#include "types.h"
#include "visualizer/sketchpad.h"
#include "elements/ghost.h"
#include "elements/pacman.h"
#include <elements/empty.h>

using namespace std;

namespace finalproject {

    struct Game {
        visualizer::Sketchpad sketchpad_ = visualizer::Sketchpad(glm::vec2(Configuration::WINDOW_MARGIN, Configuration::WINDOW_MARGIN), Configuration::GRID_SIZE, Configuration::WINDOW_SIZE - 2 * Configuration::WINDOW_MARGIN, 0);
        vector<Ghost> ghosts_ = vector<Ghost>();
        Pacman pacman_;
        size_t score_;
    };

    class Controller {

    public:
        Controller() = default;
        void setUpGame();
        void update();
        void draw();
        void processMove(Direction direction);
        void processAction(Action action);

    private:
        void calculateNewGhostPosition(Ghost ghost);
        Point determineNewPoint(Direction direction);
        double distanceToPacman(Point a, Point b);
        Configuration config_;
        Game game_;
        std::shared_ptr<Empty> empty_ = shared_ptr<Empty>(new Empty());
    };

}
#endif //FINAL_PROJECT_CONTROLLER_H
