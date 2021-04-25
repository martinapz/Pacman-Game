#ifndef FINAL_PROJECT_DOOR_H
#define FINAL_PROJECT_DOOR_H

#include "element_interfaces.h"

namespace finalproject {

namespace elements {

    class Door : public StaticElement {
    public:
        Door() = default;

        void draw(size_t row, size_t col) const;

    private:
        ci::Color color_ = ci::Color("lightskyblue");
    };

} //namespace elements
} //namespace finalproject

#endif //FINAL_PROJECT_DOOR_H
