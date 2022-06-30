#include "Fixed.hpp"

// Constructors
Fixed::Fixed(void) //: _value(0)
{
	std::cout << "\e[0;33mDefault Constructor called\e[0m" << std::endl;
	_value = 0;
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "\e[0;33mCopy Constructor called\e[0m" << std::endl;
	*this = copy;
}

Fixed::Fixed(const int n)
{
	std::cout << "\e[0;34mInt Constructor called\e[0m" << std::endl;
	_value = n * (1 << _fractional_bits);
}

Fixed::Fixed(const float n)
{
	std::cout << "\e[0;34mFloat Constructor called\e[0m" << std::endl;
	_value = roundf(n * (1 << _fractional_bits));
}

// Destructor
Fixed::~Fixed()
{
	std::cout << "\e[0;31mDestructor called\e[0m" << std::endl;
}

// Operators
Fixed & Fixed::operator=(const Fixed &copy)
{
	std::cout << "\e[0;36mCopy assignment operator called\e[0m" << std::endl;
	this->_value = copy._value;
	return (*this);
}

// Getters / Setters
int	Fixed::getRawBits(void) const
{
	std::cout << "\e[0;32mgetRawBits member function called\e[0m" << std::endl;
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "\e[0;32msetRawBits member function called\e[0m" << std::endl;
	_value = raw;
}

float	Fixed::toFloat(void) const
{
	return(_value / (float)(1 << _fractional_bits));
}

int		Fixed::toInt(void) const
{
	return (_value / (1 << _fractional_bits));
}

std::ostream & operator<<(std::ostream & os, const Fixed &F)
{
	os << F.toFloat();
	return (os);
}
