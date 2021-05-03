#ifndef FINAL_PROJECT_PACMAN_H
#define FINAL_PROJECT_PACMAN_H

#include "vector"
#include "element_interfaces.h"
#include "point.h"

namespace finalproject {

namespace elements {
    /**
    * Class that represents the Pacman object in the Pacman game.
    */
    class Pacman : public DynamicElement {
    public:
        /**
        * Default constructor.
        */
        Pacman() = default;

        /**
        * Constructor with parameters representing coordinates of Pacman.
         * @param i coordinate for pacman
         * @param j coordinate for pacman
         * @param texture of the pacman
        */
        Pacman(size_t i, size_t j, ci::gl::Texture2dRef texture);

        /**
        * Draws Pacman object.
        */
        void draw() const;

    private:
        float radius_ = 10;
        ci::Color color_ = ci::Color("yellow");
    };

} //namespace elements

} //namespace finalproject

#endif //FINAL_PROJECT_PACMAN_H
