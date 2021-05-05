#include <elements/coin.h>
#include "pacman_app.h"
#include "game_instructions.h"

using namespace finalproject::elements;

namespace finalproject {

    void PacmanApp::setup() {
       controller_.loadImages();
       controller_.setUpGame();
     }

    void PacmanApp::update() {
       controller_.update();
    }

    void PacmanApp::draw() {
        controller_.draw();
    }

    void PacmanApp::keyDown(ci::app::KeyEvent event) {
        switch (event.getCode()) {
            case ci::app::KeyEvent::KEY_DOWN:
                controller_.processMove(Direction::DOWN);
                break;
            case ci::app::KeyEvent::KEY_UP:
                controller_.processMove(Direction::UP);
                break;
            case ci::app::KeyEvent::KEY_LEFT:
                controller_.processMove(Direction::LEFT);
                break;
            case ci::app::KeyEvent::KEY_RIGHT:
                controller_.processMove(Direction::RIGHT);
                break;
            case ci::app::KeyEvent::KEY_SPACE:
                controller_.processAction(Action::START);
                break;
            case ci::app::KeyEvent::KEY_ESCAPE:
                controller_.processAction(Action::EXIT);
                break;
            case ci::app::KeyEvent::KEY_PAUSE:
                controller_.processAction(Action::PAUSE);
                break;
            case ci::app::KeyEvent::KEY_p:
                controller_.processAction(Action::START_LEVEL);
                break;
            default:
                break;
        }
    }

}  // namespace finalproject
