#ifndef FINAL_PROJECT_FEATURES_H
#define FINAL_PROJECT_FEATURES_H

#include <controller.h>

namespace finalproject {

namespace visualizer {
    /**
     * Class that draws the features of the game next to the sketchpad. This includes the score.
     */
    class Features {
    public:
        /**
         * Draws the features of the Game.
         * @param score of the game
         * @param level the game is on
         * @param game_status represents the current status of the game
         * @param lives of the pacman
         */
        void draw(size_t score, size_t level, Status game_status, size_t lives) const;

    private:
       /**
        * Draws the container that features are held.
        */
        void drawContainer() const;

        /**
         * Draws the features that are held inside of the container.
         * @param score of the game
         * @param level the game is on
         * @param game_status represents the current status of the game
         * @param lives of the pacman
         */
        void drawLabels(size_t score, size_t level, Status game_status, size_t lives) const;
    };

} // namespace visualizer

} // namespace finalproject

#endif //FINAL_PROJECT_FEATURES_H
