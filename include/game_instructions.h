#ifndef FINAL_PROJECT_GAME_INSTRUCTIONS_H
#define FINAL_PROJECT_GAME_INSTRUCTIONS_H

#include <string>

namespace finalproject {
    /**
     * Struct for Configuration of the game
     */
    struct Configuration {
        constexpr static const size_t PIXEL_SIZE = 40;
        constexpr static const size_t GRID_SIZE = 23;
        constexpr static const size_t GRID_CENTER_X = GRID_SIZE / 2;
        constexpr static const size_t WINDOWS_SIZE_X = 1500;
        constexpr static const size_t WINDOWS_SIZE_Y = 1000;
        constexpr static const size_t WINDOW_MARGIN = PIXEL_SIZE;
        constexpr static const double SKETCHPAD_SIZE = GRID_SIZE  * PIXEL_SIZE + 2  * PIXEL_SIZE;
        constexpr static const size_t COIN_VALUE = 10;
        constexpr static const long NUMBER_OF_LEVELS = 2;
        constexpr static const long NUMBER_OF_LIVES = 3;

        constexpr static const long SECONDS_TO_RELEASE_GHOSTS = 5;
        const std::string LEVEL_DATA_FILE = "C:\\Users\\marti\\CLionProjects\\cinder_master\\My-Projects\\final-project-martinapz\\data\\level";
    };

    /**
     * Enum representing the possible actions in the game
     */
    enum Action {
        START,
        EXIT,
        PAUSE,
        START_LEVEL
    };

    /**
     * Enum to represent the possible directions to go in the game
     */
    enum Direction {
        LEFT,
        RIGHT,
        UP,
        DOWN
    };

    /**
     * Enum to represent the status of the game
     */
    enum Status {
        NOT_STARTED,
        ACTIVE,
        PAUSED,
        OVER,
        GAME_WINNER,
        LEVEL_WON,
        LIFE_LOST
    };
} //namespace finalproject

#endif //FINAL_PROJECT_GAME_INSTRUCTIONS_H
