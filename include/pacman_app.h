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

    class PacmanApp : public ci::app::App {
    public:

        PacmanApp();

        void setup() override;

        void draw() override;

        void update() override;

        void keyDown(cinder::app::KeyEvent event) override;

    private:
        Controller controller_;
    };
}  // namespace finalproject

#endif  // PACMAN_APP_H
