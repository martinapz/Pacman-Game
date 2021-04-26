#include "elements/coin.h"

namespace finalproject {

namespace elements {

    void Dot::draw(size_t row, size_t col) const {
        drawCircle(row, col, color_, radius_);
    }

} //namespace elements
} //namespace finalproject
