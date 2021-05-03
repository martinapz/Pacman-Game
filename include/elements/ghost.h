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
        Ghost(size_t i, size_t j, ci::gl::Texture2dRef texture, ci::gl::Texture2dRef immunity_ghost_texture);

        /**
        * Draws the Ghost object
        */
        void draw() const;

        void drawInactive() const;

     private:
        float radius_ = 8;
        ci::Color color_ = ci::Color("red");
        bool isActive_ = false;
        ci::gl::Texture2dRef immunity_ghost_texture_;
    };

} //namespace elements
} //namespace finalproject

#endif //FINAL_PROJECT_GHOST_H
