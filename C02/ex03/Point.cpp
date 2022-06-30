#include "Point.hpp"

// Constructors
Point::Point(void) : _x(0), _y(0)
{
	// std::cout << "\e[0;33mDefault Constructor called\e[0m" << std::endl;
}

Point::Point(Point const & copy) : _x(copy._x), _y(copy._y)
{
	// std::cout << "\e[0;33mCopy Constructor called\e[0m" << std::endl;
}

Point::Point(float const x, float const y) : _x(x), _y(y)
{
	// std::cout << "\e[0;34mInt Constructor called\e[0m" << std::endl;
}

// Operator overloads
Point & Point::operator=(Point & copy)
{
	// std::cout << "\e[0;36mCopy assignment operator called\e[0m" << std::endl;
	(void) copy;
	return (*this);
}

Point const & Point::operator=(Point const & copy)
{
	(void) copy;
	return (*this);
}

// Getters / Setters
Fixed	Point::getX(void) const
{
	// std::cout << "\e[0;32mgetRawBits member function called\e[0m" << std::endl;
	return (this->_x.toFloat());
}

Fixed	Point::getY(void) const
{
	// std::cout << "\e[0;32mgetRawBits member function called\e[0m" << std::endl;
	return (this->_y.toFloat());
}


// Destructor
Point::~Point()
{
	// std::cout << "\e[0;31mDestructor called\e[0m" << std::endl;
}

std::ostream & operator<<(std::ostream & os, Point const &P)
{
	os << "[" << P.getX() << "," << P.getY() << "]";
	return (os);
}