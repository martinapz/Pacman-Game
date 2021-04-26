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
            * Draws the features of the Game
            */
            void draw() const;

        private:
            void drawContainer() const;

            void drawLabels() const;
        };

} // namespace visualizer
} // namespace finalproject

#endif //FINAL_PROJECT_FEATURES_H
