#include <elements/coin.h>
#include "pacman_app.h"
#include "types.h"

using namespace finalproject::elements;

namespace finalproject {

    PacmanApp::PacmanApp() {}

    void PacmanApp::setup() {
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
            default:
                break;
        }
    }
}  // namespace finalproject
