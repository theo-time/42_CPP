#include "Point.hpp"

Point::Point()
{

}

Point::Point(const Point &point):_x(point.getX()), _y(point.getY()) 
{
}

Point::Point(float x, float y): _x(x), _y(y) 
{

}

Point::~Point()
{

}

Point& Point::operator=(const Point &point)
{
    (void) point;
    // Point new_point(point);
    // // this = new_point();
    // return new_point;
    return *this;
}

Fixed Point::getX() const
{
    return _x;
}

Fixed Point::getY() const
{
    return _y;
}