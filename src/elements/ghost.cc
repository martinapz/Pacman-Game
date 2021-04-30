#include <elements/ghost.h>

namespace finalproject {

namespace elements {

    Ghost::Ghost(size_t i, size_t j, ci::gl::Texture2dRef texture) {
        position_ = Point(i, j);
        direction_ = Direction::UP;
        texture_ = texture;
    }

    void Ghost::draw() const {
        drawTexture(position_.getX(), position_.getY(), texture_);
    }

} //namespace elements
} //namespace finalproject

