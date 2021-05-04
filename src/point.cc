#include "point.h"

namespace finalproject {

    Point::Point(size_t x_coordinate, size_t y_coordinate) {
        x_ = x_coordinate;
        y_ = y_coordinate;
    }

    size_t Point::getX() const {
        return x_;
    }

    size_t Point::getY() const {
        return y_;
    }

    void Point::setX(size_t x) {
        x_ = x;
    }

    void Point::setY(size_t y) {
        y_ = y;
    }

} //namespace finalproject