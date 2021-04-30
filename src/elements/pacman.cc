#include <elements/pacman.h>

namespace finalproject {

namespace elements {

    Pacman::Pacman(size_t i, size_t j) {
        position_ = Point(i, j);
        direction_ = Direction::RIGHT;
    }

    void Pacman::draw() const {
        drawCircle(position_.getX(),position_.getY(),color_, radius_);
    }

} //namespace elements
} //namespace finalproject
