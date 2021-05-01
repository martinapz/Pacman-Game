#ifndef FINAL_PROJECT_GHOST_CONTAINER_H
#define FINAL_PROJECT_GHOST_CONTAINER_H

namespace finalproject {
namespace elements {

    /**
    * Class that represents the Dot object in the Pacman game.
    */
    class GhostContainer : public StaticElement {
    public:
        /**
        * Default constructor for Empty object
        */
        GhostContainer() = default;

        /**
        * Draws each ghost container
        */
        void draw(size_t row, size_t col) const;

        void setIsOpen(bool isOpen);

        bool isOpen();

    private:
        ci::Color color_ = ci::Color("black");
        bool isOpen_ = false;

    };

} //namespace elements
} //namespace finalproject



#endif //FINAL_PROJECT_GHOST_CONTAINER_H
