#include "elements/immunity.h"

namespace finalproject {

namespace elements {

    void Immunity::draw(size_t row, size_t col) const {
        drawCircle(row, col, color_, radius_);
    }

} //namespace elements
} //namespace finalproject
