#ifndef FIXED_HPP
#include <iostream>

class Fixed {

  private:
    int _nb;
    const static int _fract_bits = 8;

  public:
    Fixed();
    Fixed(const Fixed &fixed);
    void operator=(const Fixed &fixed);
    ~Fixed();

    int getRawBits( void ) const;
    void setRawBits( int const raw );

};

#endif