#include "Fixed.hpp"

// Constructors
Fixed::Fixed()
{
	_value = 0;
	std::cout << "\e[0;33mDefault Constructor called of Fixed\e[0m" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
	_value = copy.getValue();
	std::cout << "\e[0;33mCopy Constructor called of Fixed\e[0m" << std::endl;
}

Fixed::Fixed(int value)
{
	_value = value;
	std::cout << "\e[0;33mFields Constructor called of Fixed\e[0m" << std::endl;
}


// Destructor
Fixed::~Fixed()
{
	std::cout << "\e[0;31mDestructor called of Fixed\e[0m" << std::endl;
}


// Operators
Fixed & Fixed::operator=(const Fixed &assign)
{
	_value = assign.getValue();
	return *this;
}


// Getters / Setters
