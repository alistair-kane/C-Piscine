#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include <string>
#include <cmath>
#include <stdexcept>
#include "Fixed.hpp"

class Point
{
	public:
		// Constructors
		Point(void);
		// Copy (cannonical)
		Point(Point const & copy);
		Point(float const x, float const y);

		// Destructor
		~Point(void);
		
		// Operators
		Point	& operator=(Point & copy);
		Point const & operator=(Point const & copy);
	
		// Getters / Setters
		Fixed	getX(void) const;
		Fixed	getY(void) const;

	private:
		Fixed const	_x;
		Fixed const	_y;

};

std::ostream	& operator<<(std::ostream &os, const Point &P);
bool 			bsp(Point const a, Point const b, Point const c, Point const point);

#endif