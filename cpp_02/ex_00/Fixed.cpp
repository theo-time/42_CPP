#include "Fixed.hpp"

Fixed::Fixed()
{
    _nb = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
    std::cout << "Copy constructor called" << std::endl;
    _nb = fixed.getRawBits();
}

void Fixed::operator=(const Fixed &fixed)
{
    std::cout << "Copy assignment operator called" << std::endl; 
    _nb = fixed.getRawBits();
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