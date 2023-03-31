#include <iostream>
#include "Fixed.hpp"

// int main( void ) {
//     Fixed a;
//     Fixed b( 10 );
//     Fixed c( 42.42f );
//     Fixed d( b );
//     a = Fixed( 1234.4321f );
//     std::cout << "a is " << a << std::endl;
//     std::cout << "b is " << b << std::endl;
//     std::cout << "c is " << c << std::endl;
//     std::cout << "d is " << d << std::endl;

//     std::cout << "a + b is " << a + b << std::endl;
//     std::cout << "b - b is " << b - b << std::endl;
//     std::cout << "a++ is " << a++ << std::endl;
//     std::cout << "a is " << a << std::endl;
//     std::cout << "++a is " << ++a << std::endl;
//     std::cout << "d is " << d << std::endl;

//     std::cout << "a < b " << (a < b) << std::endl;
//     std::cout << "a <= b " << (a <= b) << std::endl;
//     std::cout << "a == b " << (a == b) << std::endl;
//     std::cout << "a != b " << (a != b) << std::endl;


//     std::cout << "min(a,b) " << Fixed::min(a,b) << std::endl;
//     std::cout << "max(a,b) " << Fixed::max(a,b) << std::endl;
//     // Fixed const a( 1.125f );
//     // // Fixed const b( 1.5f );
//     // // Fixed const c( 256.5f );

//     // std::cout << a << std::endl;
//     // std::cout << "b is " << b << std::endl;
//     // std::cout << "c is " << c << std::endl;
//     }

// int main( void ) {
//     Fixed a;
//     Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
//     std::cout << a << std::endl;
//     std::cout << ++a << std::endl;
//     std::cout << a << std::endl;
//     std::cout << a++ << std::endl;
//     std::cout << a << std::endl;
//     std::cout << b << std::endl;
//     std::cout << Fixed::max( a, b ) << std::endl;
//     return 0;
// }

int main( void ) {
    Fixed a(-10);
    Fixed const b(-3);
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << a / b << std::endl;
    std::cout << -10.0f / -3.0f << std::endl;
    return 0;
}