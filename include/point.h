#ifndef FINAL_PROJECT_POINT_H
#define FINAL_PROJECT_POINT_H

namespace finalproject {

    /**
     * A point class to represent the location of a moving object.
     */
    class Point {
    public:
       /**
        * Default constructor
        */
        Point() = default;

       /**
        * Constructor
        */
        Point(size_t x_coordinate, size_t y_coordinate);

        /**
        * Get x coordinate
        */
        size_t getX() const;

        /**
        * Get y coordinate
        */
        size_t getY() const;

        /**
        * Set x coordinate
        */
        void setX(size_t x);

        /**
        * Set y coordinate
        */
        void setY(size_t y);

    private:
        size_t x_;
        size_t y_;
    };

} // namespace finalproject
#endif //FINAL_PROJECT_POINT_H
