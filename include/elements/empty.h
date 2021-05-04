#ifndef FINAL_PROJECT_EMPTY_H
#define FINAL_PROJECT_EMPTY_H

#include "element_interfaces.h"

namespace finalproject {

namespace elements {
    /**
     * Class that represents the Dot object in the Pacman game.
     */
    class Empty : public StaticElement {
    public:
        /**
         * Default constructor for Empty object
         */
        Empty() = default;

        /**
         * Draws the Empty element
         */
        void draw(size_t row, size_t col) const;

    private:
        ci::Color color_ = ci::Color("black");
    };

} //namespace elements

} //namespace finalproject

#endif //FINAL_PROJECT_EMPTY_H
