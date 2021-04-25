#include <elements/ghost.h>

namespace finalproject {

namespace elements {

    Ghost::Ghost(size_t i, size_t j) {
        position_ = Point(i, j);
        direction_ = Direction::UP;
    }

    void Ghost::draw() const {
        drawCircle(position_.getX(),position_.getY(),color_, radius_);
    }

} //namespace elements
} //namespace finalproject

