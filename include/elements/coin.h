#ifndef FINAL_PROJECT_COIN_H
#define FINAL_PROJECT_COIN_H

#include "element_interfaces.h"

namespace finalproject {

namespace elements {
   /**
    * Class that represents the Coin object in the Pacman game.
    */
    class Coin : public StaticElement {
    public:
        Coin() = default;

        void draw(size_t row, size_t col) const;
    private:
        ci::Color color_ = ci::Color("white");
        float radius_ = 5;

    };

} //namespace elements
} //namespace finalproject

#endif //FINAL_PROJECT_COIN_H
