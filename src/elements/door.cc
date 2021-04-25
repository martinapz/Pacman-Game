#include "elements/door.h"

namespace finalproject {

namespace elements {

    void Door::draw(size_t row, size_t col) const {
        drawSquare(row, col, color_);
    }

} //namespace elements
} //namespace finalproject