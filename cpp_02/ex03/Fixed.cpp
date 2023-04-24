#include "Fixed.hpp"

void    print_bits(int n)
{
    std::bitset<32> bits(n);
    std::cout << bits << std::endl;
}

Fixed::Fixed()
{
    _nb = 0;
    // std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int nb)
{
    _nb = nb << _fract_bits;
    // std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float nb)
{
    _nb = roundf(nb  * ( 1 << _fract_bits));
    // std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
    // std::cout << "Copy constructor called" << std::endl;
    _nb = fixed.getRawBits();
}

Fixed& Fixed::operator=(const Fixed &fixed)
{
    // std::cout << "Copy assignment operator called" << std::endl; 
    _nb = fixed.getRawBits();
    return (*this);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    float float_nb = ((float )(fixed.getRawBits()) ) / (1 << 8);
    os << float_nb ;
    return (os);
}

Fixed::~Fixed()
{
    // std::cout << "Destructor called" << std::endl; 
}

int Fixed::getRawBits( void ) const
{
    // std::cout << "getRawBits member function called" << std::endl; 
    return _nb;
}

void Fixed::setRawBits( int const raw )
{
    _nb = raw;
    // std::cout << "getRawBits member function called" << std::endl; 
}

float Fixed::toFloat( void ) const
{
    return (float) _nb;
}

int Fixed::toInt( void ) const
{
    return (_nb >> _fract_bits);
}

// --------------- COMPARISONS -------------------

int Fixed::operator>(const Fixed &fixed) { return (_nb > fixed._nb);}
int Fixed::operator<(const Fixed &fixed) { return (_nb < fixed._nb);}
int Fixed::operator>=(const Fixed &fixed) { return (_nb >= fixed._nb);}
int Fixed::operator<=(const Fixed &fixed) { return (_nb <= fixed._nb);}
int Fixed::operator==(const Fixed &fixed) { return (_nb == fixed._nb);}
int Fixed::operator!=(const Fixed &fixed) { return (_nb != fixed._nb);}


// --------------- OPERATIONS -------------------

Fixed Fixed::operator+(const Fixed &fixed)
{
    Fixed result;
    result.setRawBits(fixed.getRawBits() + this->_nb);
    return result;
}

Fixed Fixed::operator-(const Fixed &fixed)
{
    Fixed result;
    result.setRawBits(this->_nb - fixed.getRawBits());
    return result;
}

Fixed Fixed::operator*(const Fixed &fixed)
{
    Fixed result;
    result.setRawBits((this->_nb * fixed.getRawBits()) >> _fract_bits);
    return result;
}

Fixed Fixed::operator/(const Fixed& other)
{
    if (other._nb == 0)
    {
        // Handle division by zero by throwing an exception or
        // returning a special value to indicate an error
        throw std::invalid_argument("Division by zero");
        // Or return a special value like NaN or infinity, depending
        // on your needs and the conventions of your application
        // return Fixed(std::numeric_limits<int>::max());
    }

    // Compute the absolute values of the raw values and shift
    // them to the left by the number of fractional bits
    // int abs_raw_dividend = abs(_nb);
    // int abs_raw_divisor = abs(other._nb);

    // Compute the absolute value of the quotient as a float
    float abs_quotient = (float) _nb  / (float) other.getRawBits();

    // Adjust the sign of the quotient based on the signs of the operands
    // int raw_sign = (_nb < 0) ^ (other._nb < 0) ? -1 : 1;
    // float quotient = raw_sign * abs_quotient;

    // Create a new Fixed object with the quotient value
    // and return it
    Fixed result(abs_quotient);
    return result;
}

// --------------- INCREMENTATIONS -------------------

Fixed& Fixed::operator++()
{
    this->_nb++;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp = *this;
    this->_nb ++;
    return temp;
}


Fixed& Fixed::operator--()
{
    this->_nb--;
    return *this;
}


Fixed Fixed::operator--(int)
{
    Fixed temp = *this;
    this->_nb--;
    return temp;
}

// --------------- MIN / MAX -------------------

Fixed Fixed::min(Fixed &fixed1, Fixed &fixed2)
{
    if(fixed1 <= fixed2)
        return (fixed1);
    else    
        return (fixed2);
}

Fixed Fixed::min(const Fixed &fixed1, const Fixed &fixed2)
{
    Fixed result;
    if(fixed1.getRawBits() <= fixed2.getRawBits())
        result = fixed1;
    else    
        result = fixed2;  
    return (result);
}

Fixed Fixed::max(Fixed &fixed1, Fixed &fixed2)
{
    if(fixed1 >= fixed2)
        return (fixed1);
    else    
        return (fixed2);   
}

Fixed Fixed::max(const Fixed &fixed1, const Fixed &fixed2)
{
    Fixed result;
    if(fixed1.getRawBits() >= fixed2.getRawBits())
        result = fixed1;
    else    
        result = fixed2;  
    return (result);
}