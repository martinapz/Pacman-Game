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
        /**
         * Default constructor for coin.
         */
        Coin() = default;

        /**
         * Draws the Coin object on the sketchpad.
         * @param row to draw coin
         * @param col to draw coin
         */
        void draw(size_t row, size_t col) const;

    private:
        ci::Color color_ = ci::Color("yellow");
        float radius_ = 2;
    };

} //namespace elements

} //namespace finalproject

#endif //FINAL_PROJECT_COIN_H
