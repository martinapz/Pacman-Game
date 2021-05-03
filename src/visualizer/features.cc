#include <controller.h>
#include "visualizer/features.h"

namespace finalproject {

namespace visualizer {

    void Features::draw(size_t score, size_t level, Status game_status) const {
        drawContainer();
        drawLabels(score,level, game_status);
    }

    void Features::drawContainer() const {
        ci::gl::color(ci::Color("white"));
        ci::gl::drawStrokedRect(ci::Rectf(
                vec2(1000, 50), vec2(1400, 400)));
    }
    void Features::drawLabels(size_t score, size_t level, Status game_status) const {
        string value = "SCORE: " + to_string(score);
        ci::gl::drawString(value , vec2(1050, 70), "white",ci::Font("", 30));

        value = "LEVEL: " + to_string(level);
        ci::gl::drawString(value , vec2(1050, 120), "white",ci::Font("", 30));

        if (game_status == LEVEL_WON) {
            value = "LEVEL COMPLETED. TO CONTINUE ONTO THE NEXT LEVEL, PRESS THE 'P' TO BEGIN. " + to_string(score);
            ci::gl::drawString(value, vec2(1050, 200), "white", ci::Font("", 30));
        }
    }

}
}