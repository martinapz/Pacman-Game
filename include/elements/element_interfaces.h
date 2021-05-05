#ifndef FINAL_PROJECT_ELEMENT_INTERFACES_H
#define FINAL_PROJECT_ELEMENT_INTERFACES_H

#include "game_instructions.h"
#include "point.h"
#include "cinder/gl/gl.h"

using glm::vec2;

namespace finalproject {

namespace elements {
    /**
     * Class that represents the shapes that are drawn on the sketchpad.
     */
    class Shape {
    public:
        /**
         * Draws square.
         * @param row to draw square
         * @param col to draw square
         * @param color to color in square
         */
        void drawSquare(size_t row, size_t col, ci::Color color) const {
            ci::gl::color(color);
            glm::vec2 pixel_top_left = top_left_corner_ + vec2(row * pixel_side_length_, col * pixel_side_length_);
            glm::vec2 pixel_bottom_right = pixel_top_left + vec2(pixel_side_length_, pixel_side_length_);
            ci::Rectf pixel_bounding_box(pixel_top_left, pixel_bottom_right);
            ci::gl::drawSolidRect(pixel_bounding_box);
        }

        /**
         * Draws circle.
         * @param row to draw circle
         * @param col to draw circle
         * @param color to color in circle
         * @param radius of the circle
         */
        void drawCircle(size_t row, size_t col, ci::Color color, float radius) const {
            ci::gl::color(color);
            glm::vec2 pixel_top_left = top_left_corner_ + vec2(row * pixel_side_length_, col * pixel_side_length_);
            glm::vec2 pixel_bottom_right = pixel_top_left + vec2(pixel_side_length_, pixel_side_length_);
            glm::vec2 center = midPoint(pixel_top_left, pixel_bottom_right);
            ci::gl::drawSolidCircle(center, radius);
        }

        /**
         * Draws a texture.
         * @param row to draw texture
         * @param col to draw texture
         * @param texture that will be drawn
         */
        // Load images -https://libcinder.org/docs/guides/opengl/part4.html
        void drawTexture(size_t row, size_t col, ci::gl::Texture2dRef texture) const {
            ci::gl::color(ci::Color("white"));
            glm::vec2 pixel_top_left = top_left_corner_ + vec2(row * pixel_side_length_, col * pixel_side_length_);
            glm::vec2 pixel_bottom_right = pixel_top_left + vec2(pixel_side_length_, pixel_side_length_);
            ci::Area area = ci::Area(pixel_top_left, pixel_bottom_right);
            ci::gl::draw(texture, area);
        }

        /**
         * Calculates midPoint for circle.
         * @param p1 the first point
         * @param p2 the second point
         * @return the midpoint between the two points
         */
        glm::vec2 midPoint(glm::vec2 p1, glm::vec2 p2) const {
            return glm::vec2((p1.x + p2.x) /2,(p1.y + p2.y) /2) ;
        }

    protected:
        double pixel_side_length_ = (Configuration::SKETCHPAD_SIZE - 2 * Configuration::WINDOW_MARGIN) / Configuration::GRID_SIZE;
        glm::vec2 top_left_corner_ = glm::vec2(Configuration::WINDOW_MARGIN, Configuration::WINDOW_MARGIN);
    };

    /**
     * An interface that represents the parts of the Pacman game that do not move.
     * This includes the walls, the coins, and the dots.
     */
    class StaticElement : public Shape {
    public:
        /**
         * Draws Static element.
         * @param row to draw element
         * @param col to draw element
         */
        virtual void draw(size_t row, size_t col) const = 0;
    };

    /**
     * An interface that represents the parts of the Pacman game that do move.
     * This includes the Pacman and the ghosts
     */
    class DynamicElement : public Shape {
    public:
        /**
         * Draws Dynamic Element.
         */
        virtual void draw() const = 0;

        /**
         * Gets position of element.
         */
        Point getPosition() const {
            return position_;
        }

        /**
         * Sets position of element.
         * @param x component
         * @param y component
         */
        void setPosition(size_t x, size_t y) {
            position_.setX(x);
            position_.setY(y);
        }

        /**
         * Gets the direction of the element.
         */
        Direction getDirection() const {
            return direction_;
        }

        /**
         * Sets the direction of the element.
         * @param direction
         */
        void setDirection(Direction direction) {
            direction_ = direction;
        }

    protected:
        Point position_;
        Direction direction_;
        ci::gl::Texture2dRef texture_;
    };

    typedef std::vector<std::vector<std::shared_ptr<StaticElement>>> static_elements_vector;

} // namespace elements

} // namespace finalproject

#endif //FINAL_PROJECT_ELEMENT_INTERFACES_H
