#include <elements/ghost.h>

namespace finalproject {

namespace elements {

    Ghost::Ghost(size_t i, size_t j, ci::gl::Texture2dRef texture, ci::gl::Texture2dRef immunity_ghost_texture) {
        position_ = Point(i, j);
        direction_ = Direction::UP;
        texture_ = texture;
        immunity_ghost_texture_ = immunity_ghost_texture;
    }

    void Ghost::draw() const {
        drawTexture(position_.getX(), position_.getY(), texture_);
    }

    void Ghost::drawInactive() const {
        drawTexture(position_.getX(), position_.getY(), immunity_ghost_texture_);
    }

} //namespace elements
} //namespace finalproject

