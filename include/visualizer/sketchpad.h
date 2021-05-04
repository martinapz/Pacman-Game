#pragma once

#include <game_instructions.h>
#include "cinder/gl/gl.h"
#include "elements/element_interfaces.h"

using namespace finalproject::elements;

namespace finalproject {

namespace visualizer {
    /**
     * This class represents the Sketchpad, which is where the pacman game is drawn and played on.
     */
    class Sketchpad {
    public:
        /**
         * Default constructor for Sketchpad.
         */
        Sketchpad() = default;

        /**
         * Constructor.
         */
        Sketchpad(const glm::vec2& top_left_corner, size_t num_pixels_per_side,
                    double sketchpad_size, double brush_radius = 1.15);

        /**
         * Draws the Sketchpad.
         */
        void draw() const;

        /**
         * Sets the vector of static elements.
         * @param static_elements will set the static elements vector
         */
        void SetStaticElements(static_elements_vector static_elements);

        /**
         * Gets the vector of static elements.
         * @return vector of pointers of static elements
         */
        static_elements_vector& GetStaticElements();

    private:
        glm::vec2 top_left_corner_;
        size_t num_pixels_per_side_;
        double pixel_side_length_;
        static_elements_vector static_elements_;
    };

}  // namespace visualizer

}  // namespace finalproject
