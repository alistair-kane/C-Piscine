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

// Destructor
Fixed::~Fixed()
{
	std::cout << "\e[0;31mDestructor called\e[0m" << std::endl;
}

// Operators
Fixed & Fixed::operator=(const Fixed &copy)
{
	std::cout << "\e[0;36mCopy assignment operator called\e[0m" << std::endl;
	this->_value = copy.getRawBits();
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