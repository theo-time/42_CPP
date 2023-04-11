#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <cmath>
#include <bitset>

class Fixed {

  private:
    int _nb;
    const static int _fract_bits = 8;

  public:
    Fixed();
    Fixed(const int nb);
    Fixed(const float nb);
    Fixed(const Fixed &fixed);
    Fixed& operator=(const Fixed &fixed);
    friend std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
    ~Fixed();

    int getRawBits( void ) const;
    void setRawBits( int const raw );

    float toFloat( void ) const;
    int toInt( void ) const;
};

#endif