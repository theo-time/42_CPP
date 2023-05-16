#include <iostream>
#include <string>

#include "whatever.h"

// int main()
// {
//     std::string a = "A";
//     std::string b = "B";
//     int c = 55;
//     int d = 32;
//     swap(a,b);

//     std::cout << a << std::endl;
//     std::cout << b << std::endl;
//     std::cout << "min : " << min(c,d) << std::endl;
// }

int main( void ) {
    int a = 2;
    int b = 3;
    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
    return 0;
}