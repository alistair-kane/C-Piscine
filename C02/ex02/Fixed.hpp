#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>
#include <stdexcept>

class Fixed
{
	public:
		// Constructors
		Fixed(void);
		// Copy (cannonical)
		Fixed(Fixed const & copy);
		
		Fixed(const int n);
		Fixed(const float n);
		// Destructor
		~Fixed(void);
		
		// Operators
		Fixed	& operator=(const Fixed &copy);
		bool	operator==(const Fixed &rhs);
		bool	operator!=(const Fixed &rhs);
		bool	operator>(const Fixed &rhs);
		bool	operator<(const Fixed &rhs);
		bool	operator<=(const Fixed &rhs);
		bool	operator>=(const Fixed &rhs);

		Fixed	operator+(const Fixed &rhs);
		Fixed	operator-(const Fixed &rhs);
		Fixed	operator*(const Fixed &rhs);
		Fixed	operator/(const Fixed &rhs);

		Fixed	& operator++();
		Fixed	operator++(int);
		Fixed	& operator--();
		Fixed	operator--(int);
	
		// Getters / Setters
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		// member functions
		float	toFloat(void) const;
		int		toInt(void) const;

		static Fixed & min(Fixed &a, Fixed &b);
		static const Fixed & min(const Fixed &a, const Fixed &b);
		static Fixed & max(Fixed &a, Fixed &b);
		static const Fixed & max(const Fixed &a, const Fixed &b);

	private:
		int 				_value;
		static const int	_fractional_bits = 8;


};

std::ostream	& operator<<(std::ostream &os, const Fixed &F);

#endif