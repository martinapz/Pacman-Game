#ifndef FINAL_PROJECT_TYPES_H
#define FINAL_PROJECT_TYPES_H

#include <string>

namespace finalproject {
        struct Configuration {
            constexpr static const double WINDOW_SIZE = 875;
            constexpr static const double WINDOW_MARGIN = 100;
            constexpr static const size_t GRID_SIZE = 23;
            const std::string LEVEL_DATA_FILE = "C:\\Users\\marti\\CLionProjects\\cinder_master\\My-Projects\\final-project-martinapz\\data\\level1.txt";
        };

        enum ELEMENT {
            PACMAN,
            WALL,
            DOT,
            COIN,
            GHOST,
            DOOR,
            EMPTY
        };
}

#endif //FINAL_PROJECT_TYPES_H
