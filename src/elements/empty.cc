#include "elements/empty.h"

namespace finalproject {

namespace elements {
    void Empty::draw(size_t row, size_t col) const {
        drawSquare(row, col, color_);
    }



} //namespace elements
} //namespace finalproject