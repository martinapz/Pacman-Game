#ifndef FINAL_PROJECT_IMMUNITY_H
#define FINAL_PROJECT_IMMUNITY_H

#include "element_interfaces.h"

namespace finalproject {

namespace elements {
   /**
    * Class that represents the Immunity object in the Pacman game.
    */
    class Immunity : public StaticElement {
    public:
        /**
        * Default constructor for Immunity object
        */
        Immunity() = default;

        /**
        * Draws the immunity object
        */
        void draw(size_t row, size_t col) const;
    private:
        ci::Color color_ = ci::Color("white");
        float radius_ = 5;

    };

} //namespace elements
} //namespace finalproject

#endif //FINAL_PROJECT_IMMUNITY_H
