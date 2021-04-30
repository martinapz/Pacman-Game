#ifndef FINAL_PROJECT_DOOR_H
#define FINAL_PROJECT_DOOR_H

#include "element_interfaces.h"

namespace finalproject {

namespace elements {
    /**
    * Class that represents the Door object in the Pacman game.
    */
    class Door : public StaticElement {
    public:
        /**
        * Default constructor for Door object
        */
        Door() = default;

        /**
        * Draws the Door on the sketchpad
        */
        void draw(size_t row, size_t col) const;

        void setIsOpen(bool isOpen);

    private:
        bool isOpen_ = false;
        ci::Color color_ = ci::Color("black");
    };

} //namespace elements
} //namespace finalproject

#endif //FINAL_PROJECT_DOOR_H
