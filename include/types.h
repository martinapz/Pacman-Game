#ifndef FINAL_PROJECT_TYPES_H
#define FINAL_PROJECT_TYPES_H

#include <string>

namespace finalproject {
    /**
     * Struct for Configuration of the game
     */
    struct Configuration {
        constexpr static const size_t PIXEL_SIZE = 40;
        constexpr static const size_t GRID_SIZE = 23;
        constexpr static const size_t WINDOW_MARGIN = PIXEL_SIZE;
        constexpr static const double SKETCHPAD_SIZE = GRID_SIZE  * PIXEL_SIZE + 2  * PIXEL_SIZE;
        const std::string LEVEL_DATA_FILE = "C:\\Users\\marti\\CLionProjects\\cinder_master\\My-Projects\\final-project-martinapz\\data\\level1.txt";
    };

    /**
     * Enum representing the possible actions in the game
     */
    enum Action {
        START,
        EXIT,
        PAUSE
    };

    /**
     * Enum to represent the possible directions to go in the game
     */
    enum Direction {
        LEFT,
        RIGHT,
        UP,
        DOWN,
        NONE
    };
}

#endif //FINAL_PROJECT_TYPES_H
