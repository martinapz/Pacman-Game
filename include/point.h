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

        size_t getX() const;

        size_t getY() const;

        void setX(size_t x);

        void setY(size_t y);

    private:
        size_t x_;
        size_t y_;
    };

} // namespace finalproject
#endif //FINAL_PROJECT_POINT_H
