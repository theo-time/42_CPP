#ifndef POINT_HPP
#include "Fixed.hpp"

class Point {

  private:
    const Fixed _x;
    const Fixed _y;

  public:
    Point();
    Point(const Point &point);
    Point(const Fixed &x, const Fixed &y);
    Point(float x, float y);
    ~Point();

    Point& operator=(const Point &point);

    Fixed getX() const;
    Fixed getY() const;
};

#endif