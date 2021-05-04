#include "elements/wall.h"

namespace finalproject {

namespace elements {

    void Wall::draw(size_t row, size_t col) const {
        drawSquare(row, col, color_);
    }

} //namespace elements

} //namespace finalproject
