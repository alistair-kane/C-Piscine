#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

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
		Fixed & operator=(const Fixed &copy);
		
		// Getters / Setters
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

	private:
		int 				_value;
		static const int	_fractional_bits = 8;

};

#endif