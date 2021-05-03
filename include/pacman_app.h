#pragma once

#ifndef PACMAN_APP_H
#define PACMAN_APP_H

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "controller.h"

using namespace std;
using namespace finalproject::elements;

namespace finalproject {
    /**
     * App for visualizing the Pacman game
     */
    class PacmanApp : public ci::app::App {
    public:
        /**
        * Default constructor
        */
        PacmanApp();

        /**
        * Set up the Pacman game
        */
        void setup() override;

        /**
        * Draws the Pacman game
        */
        void draw() override;

        /**
        * Updates the game
        */
        void update() override;

        /**
        * Updates direction based on user input
        */
        void keyDown(cinder::app::KeyEvent event) override;

    private:
        Controller controller_;
    };
}  // namespace finalproject

#endif  // PACMAN_APP_H
