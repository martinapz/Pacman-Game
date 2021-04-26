#include <controller.h>
#include "visualizer/features.h"

namespace finalproject {

namespace visualizer {

    void Features::drawLabels() {
        ci::gl::drawString("SCORE" , vec2(1000, 50), "white",ci::Font("", 20.0f));
    }

}
}