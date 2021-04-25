#ifndef FINAL_PROJECT_WALL_H
#define FINAL_PROJECT_WALL_H

#include "element_interfaces.h"

namespace finalproject {

namespace elements {
   /**
    * Class that represents the Wall object in the Pacman game.
    */
    class Wall : public StaticElement {
    public:
        Wall() = default;

        void draw(size_t row, size_t col) const;

    private:
        ci::Color color_ = ci::Color("blue");
    };

} //namespace elements
} //namespace finalproject

#endif //FINAL_PROJECT_WALL_H
