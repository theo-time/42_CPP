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

    Fixed operator+(const Fixed &fixed);
    Fixed operator-(const Fixed &fixed);
    Fixed operator*(const Fixed &fixed);
    Fixed operator/(const Fixed &fixed);

    Fixed& operator++();
    Fixed operator++(int);
    Fixed& operator--();
    Fixed operator--(int);

    int operator>(const Fixed &fixed);
    int operator<(const Fixed &fixed);
    int operator>=(const Fixed &fixed);
    int operator<=(const Fixed &fixed);
    int operator==(const Fixed &fixed);
    int operator!=(const Fixed &fixed);

    
    ~Fixed();

    int getRawBits( void ) const;
    void setRawBits( int const raw );

    float toFloat( void ) const;
    int toInt( void ) const;

    static Fixed min(Fixed &fixed1, Fixed &fixed2);
    static Fixed min(const Fixed &fixed1, const Fixed &fixed2);    
    static Fixed max(Fixed &fixed1, Fixed &fixed2);
    static Fixed max(const Fixed &fixed1, const Fixed &fixed2);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif