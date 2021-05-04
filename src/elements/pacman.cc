#include <elements/pacman.h>

namespace finalproject {

namespace elements {

    Pacman::Pacman(size_t i, size_t j, ci::gl::Texture2dRef texture) {
        position_ = Point(i, j);
        direction_ = Direction::RIGHT;
        texture_ = texture;
    }

    void Pacman::draw() const {
        // https://libcinder.org/docs/guides/opengl/part1.html#transformations
        glm::vec2 pixel_top_left = top_left_corner_ + vec2(position_.getX() * pixel_side_length_, position_.getY() * pixel_side_length_);
        ci::gl::pushModelMatrix();
        switch (direction_) {
            case Direction::RIGHT :
                // translate using top left corner
                ci::gl::translate(pixel_top_left);
                ci::gl::rotate(float(0));
                break;
            case Direction::UP :
                // translate using bottom left corner
                ci::gl::translate(pixel_top_left + vec2(0, pixel_side_length_));
                ci::gl::rotate(float(270 * M_PI / 180));
                break;
            case Direction::DOWN :
                // translate using top right corner
                ci::gl::translate(pixel_top_left + vec2(pixel_side_length_, 0));
                ci::gl::rotate(float(90 * M_PI / 180));
                break;
            case Direction::LEFT :
                // translate using bottom right corner
                ci::gl::translate(pixel_top_left + vec2(pixel_side_length_, pixel_side_length_));
                ci::gl::rotate(float(180 * M_PI / 180));
                break;
        };
        ci::gl::color(ci::Color("white"));
        ci::gl::draw(texture_);
        ci::gl::popModelMatrix();
    }

} //namespace elements

} //namespace finalproject
