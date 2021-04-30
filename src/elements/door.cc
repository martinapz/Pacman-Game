#include "elements/door.h"

namespace finalproject {

namespace elements {

    void Door::draw(size_t row, size_t col) const {
        drawSquare(row, col, color_);
        if (!isOpen_) {
            ci::gl::color(ci::Color("blue"));
            glm::vec2 pixel_top_left = top_left_corner_ + vec2(row * pixel_side_length_, col * pixel_side_length_ + pixel_side_length_ - 2);
            glm::vec2 pixel_bottom_right = pixel_top_left + vec2(pixel_side_length_, 2);
            ci::Rectf pixel_bounding_box(pixel_top_left, pixel_bottom_right);
            ci::gl::drawSolidRect(pixel_bounding_box);
        }
    }

    void Door::setIsOpen(bool isOpen) {
        isOpen_ = isOpen;
    }

} //namespace elements
} //namespace finalproject