#ifndef FINAL_PROJECT_DOT_H
#define FINAL_PROJECT_DOT_H

#include "element_interfaces.h"

namespace finalproject {

namespace elements {
    /**
    * Class that represents the Dot object in the Pacman game.
    */
    class Dot : public StaticElement {
    public:
        Dot() = default;

        void draw(size_t row, size_t col) const;
    private:
        ci::Color color_ = ci::Color("yellow");
        float radius_ = 2;

    };

} //namespace elements
} //namespace finalproject

#endif //FINAL_PROJECT_DOT_H
