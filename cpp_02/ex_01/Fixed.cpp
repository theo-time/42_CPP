#include "Fixed.hpp"

void    print_bits(int n)
{
    std::bitset<32> bits(n);
    std::cout << bits << std::endl;
}

// int    reverse_bits(int n)
// {
//     std::cout << "bits_before_reverse :" << std::endl;
//     print_bits(n);
//     n = (n & 0xF0) >> 4 | (n & 0x0F) << 4;
//     n = (n & 0xCC) >> 2 | (n & 0x33) << 2;
//     n = (n & 0xAA) >> 1 | (n & 0x55) << 1;
//     std::cout << "bits_after_reverse :" << std::endl;
//     print_bits(n);
//     return (n);
// }

Fixed::Fixed()
{
    _nb = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int nb)
{
    _nb = nb << _fract_bits;
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float nb)
{
    _nb = roundf(nb  * ( 1 << _fract_bits));
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
    std::cout << "Copy constructor called" << std::endl;
    _nb = fixed.getRawBits();
}

Fixed& Fixed::operator=(const Fixed &fixed)
{
    std::cout << "Copy assignment operator called" << std::endl; 
    _nb = fixed.getRawBits();
    return (*this);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return (os);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl; 
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl; 
    return _nb;
}

void Fixed::setRawBits( int const raw )
{
    _nb = raw;
    // std::cout << "getRawBits member function called" << std::endl; 
}

float Fixed::toFloat( void ) const
{
    return ((float )(this->_nb) ) / (1 << this->_fract_bits);
}

int Fixed::toInt( void ) const
{
    return (_nb >> _fract_bits);
}