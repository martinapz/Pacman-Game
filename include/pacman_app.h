#pragma once

#ifndef PACMAN_APP_H
#define PACMAN_APP_H

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "types.h"
#include "visualizer/sketchpad.h"

using namespace std;

namespace finalproject {

    struct Game {
        vector<vector<ELEMENT>> pixels_ = vector<vector<ELEMENT>>(Configuration::GRID_SIZE, vector<ELEMENT>(Configuration::GRID_SIZE));
        visualizer::Sketchpad sketchpad_ = visualizer::Sketchpad(glm::vec2(Configuration::WINDOW_MARGIN, Configuration::WINDOW_MARGIN), Configuration::GRID_SIZE, Configuration::WINDOW_SIZE - 2 * Configuration::WINDOW_MARGIN);
    };

    class PacmanApp : public ci::app::App {
    public:

        PacmanApp();

        void setup() override;

        void draw() override;

        void update() override;

        void keyDown(cinder::app::KeyEvent event) override;

        void setGame(Game game);

        ELEMENT getElement(char const pixel);

    private:
        Configuration config_;
        Game game_;
        Game setUpGame();
    };
}  // namespace finalproject

#endif  // PACMAN_APP_H
