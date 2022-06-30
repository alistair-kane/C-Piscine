#include "Fixed.hpp"

// Constructors
Fixed::Fixed(void) //: _value(0)
{
	// std::cout << "\e[0;33mDefault Constructor called\e[0m" << std::endl;
	_value = 0;
}

Fixed::Fixed(const Fixed &copy)
{
	// std::cout << "\e[0;33mCopy Constructor called\e[0m" << std::endl;
	*this = copy;
}

Fixed::Fixed(const int n)
{
	// std::cout << "\e[0;34mInt Constructor called\e[0m" << std::endl;
	_value = n * (1 << _fractional_bits);
}

Fixed::Fixed(const float n)
{
	// std::cout << "\e[0;34mFloat Constructor called\e[0m" << std::endl;
	_value = roundf(n * (1 << _fractional_bits));
}

// Destructor
Fixed::~Fixed()
{
	// std::cout << "\e[0;31mDestructor called\e[0m" << std::endl;
}

// Operator overloads
Fixed & Fixed::operator=(const Fixed &copy)
{
	// std::cout << "\e[0;36mCopy assignment operator called\e[0m" << std::endl;
	this->_value = copy._value;
	return (*this);
}

bool	Fixed::operator==(const Fixed &rhs)
{
	return (this->getRawBits() == rhs.getRawBits());
}

bool	Fixed::operator!=(const Fixed &rhs)
{
	return (this->getRawBits() != rhs.getRawBits());
}

bool	Fixed::operator>(const Fixed &rhs)
{
	return (this->getRawBits() > rhs.getRawBits());
}

bool	Fixed::operator<(const Fixed &rhs)
{
	return (this->getRawBits() < rhs.getRawBits());
}

bool	Fixed::operator<=(const Fixed &rhs)
{
	return (this->getRawBits() <= rhs.getRawBits());
}

bool	Fixed::operator>=(const Fixed &rhs)
{
	return (this->getRawBits() >= rhs.getRawBits());
}

Fixed	Fixed::operator+(const Fixed &rhs)
{
	return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed	Fixed::operator-(const Fixed &rhs)
{
	return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed	Fixed::operator*(const Fixed &rhs)
{
	Fixed	temp;

	temp = rhs.toFloat() * this->toFloat();
	return (temp);
}

Fixed	Fixed::operator/(const Fixed &rhs)
{
	if (rhs.toFloat() == 0)
		throw std::runtime_error("Impossible\n");
	return (Fixed(this->toFloat() / rhs.toFloat()));
}

Fixed & Fixed::operator++()
{
	_value++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	temp = *this;
	++*this;
	return (temp);
}

Fixed & Fixed::operator--()
{
	_value--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp = *this;
	--*this;
	return (temp);
}

std::ostream & operator<<(std::ostream & os, const Fixed &F)
{
	os << F.toFloat();
	return (os);
}

// Getters / Setters
int	Fixed::getRawBits(void) const
{
	// std::cout << "\e[0;32mgetRawBits member function called\e[0m" << std::endl;
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	// std::cout << "\e[0;32msetRawBits member function called\e[0m" << std::endl;
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

Fixed & Fixed::min(Fixed &a, Fixed &b)
{
	return (a.getRawBits() >= b.getRawBits() ? b : a);
}

const Fixed & Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a.getRawBits() >= b.getRawBits() ? b : a);
}

Fixed & Fixed::max(Fixed &a, Fixed &b)
{
	return (a.getRawBits() <= b.getRawBits() ? b : a);
}

const Fixed & Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a.getRawBits() <= b.getRawBits() ? b : a);
}