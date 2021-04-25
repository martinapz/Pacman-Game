#ifndef FINAL_PROJECT_GHOST_H
#define FINAL_PROJECT_GHOST_H

#include "element_interfaces.h"

namespace finalproject {

namespace elements {
   /**
    * Class that represents the Ghost object in the Pacman game.
    */
    class Ghost : public DynamicElement {
     public:
        Ghost() = default;

        /**
        * Constructor with parameters representing coordinates of Ghost.
        */
        Ghost(size_t i, size_t j);

        void draw() const;

     private:
        float radius_ = 8;
        ci::Color color_ = ci::Color("red");
    };

} //namespace elements
} //namespace finalproject

#endif //FINAL_PROJECT_GHOST_H
