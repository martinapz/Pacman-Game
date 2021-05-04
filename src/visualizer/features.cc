#include <controller.h>

namespace finalproject {

namespace visualizer {

    void Features::draw(size_t score, size_t level, Status game_status, size_t lives) const {
        drawContainer();
        drawLabels(score,level, game_status, lives);
    }

    void Features::drawContainer() const {
        ci::gl::color(ci::Color("white"));
        ci::gl::drawStrokedRect(ci::Rectf(
                vec2(1000, 50), vec2(1400, 400)));
    }
    void Features::drawLabels(size_t score, size_t level, Status game_status, size_t lives) const {
        std::string value = "SCORE: " + std::to_string(score);
        ci::gl::drawString(value , vec2(1050, 70), "white",ci::Font("", 30));

        value = "LEVEL: " + std::to_string(level);
        ci::gl::drawString(value , vec2(1050, 120), "white",ci::Font("", 30));

        value = "LIVES LEFT: " + std::to_string(lives - 1);
        ci::gl::drawString(value, vec2(1050, 170), "white", ci::Font("", 30));

        if (game_status == LEVEL_WON) {
            value = "LEVEL COMPLETED. TO\nCONTINUE ONTO THE NEXT\nLEVEL, PRESS THE SPACE\nTO BEGIN";
            ci::gl::drawString(value, vec2(1050, 230), "white", ci::Font("", 30));
        }

        if (game_status == IN_BETWEEN_LEVELS) {
            value = "TO START LEVEL,\nPRESS SPACE";
            ci::gl::drawString(value, vec2(1050, 230), "white", ci::Font("", 30));
        }

        if (game_status == NOT_STARTED) {
            value = "TO START GAME,\nPRESS SPACE";
            ci::gl::drawString(value, vec2(1050, 230), "white", ci::Font("", 30));
        }

        if (game_status == LIFE_LOST) {
            value = "LIFE LOST, TO RESTART\nLEVEL, PRESS P";
            ci::gl::drawString(value, vec2(1050, 230), "white", ci::Font("", 30));
        }
    }

} //namespace visualizer

} //namespace finalproject
