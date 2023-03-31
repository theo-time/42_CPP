#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main( void ) {
    Point a(-100, 100);
    Point b(100,100);
    Point c(0, 0);
    Point point(50,50);

    std::cout << bsp(point, a, b, c) << std::endl;
    std::cout << "a : " << a.getX() << " | " << a.getY() << std::endl;
    std::cout << "b : " << b.getX() << " | " << b.getY() << std::endl;
    std::cout << "c : " << c.getX() << " | " << c.getY() << std::endl;
    std::cout << "point : " << point.getX() << " | " << point.getY() << std::endl;
    return 0;
}