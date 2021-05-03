#include <controller.h>
#include "visualizer/features.h"

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
        string value = "SCORE: " + to_string(score);
        ci::gl::drawString(value , vec2(1050, 70), "white",ci::Font("", 30));

        value = "LEVEL: " + to_string(level);
        ci::gl::drawString(value , vec2(1050, 120), "white",ci::Font("", 30));

        if (game_status == LEVEL_WON) {
            value = "LEVEL COMPLETED. TO CONTINUE ONTO THE NEXT \nLEVEL, PRESS THE 'P' TO BEGIN. " + to_string(score);
            ci::gl::drawString(value, vec2(1010, 200), "white", ci::Font("", 30));
        }

        value = "LIVES LEFT: " + to_string(lives - 1);
        ci::gl::drawString(value, vec2(1050, 170), "white", ci::Font("", 30));

        if (game_status == LIFE_LOST) {
            value = "LIFE LOST. TO RESTART\n LEVEL, PRESS P. ";
            ci::gl::drawString(value, vec2(1010, 230), "white", ci::Font("", 30));
        }
    }

}
}