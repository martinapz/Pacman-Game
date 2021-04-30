#include <controller.h>
#include "visualizer/features.h"

namespace finalproject {

namespace visualizer {

    void Features::draw() const {
        drawContainer();
       // drawLabels();
    }

    void Features::drawContainer() const {
        ci::gl::color(ci::Color("white"));
        ci::gl::drawStrokedRect(ci::Rectf(
                vec2(1000, 50), vec2(1400, 400)));
    }
    void Features::drawLabels() const {
        string string = "SCORE: 50";
        ci::gl::drawString(string , vec2(1050, 70), "white",ci::Font("", 40.0f));
    }

}
}