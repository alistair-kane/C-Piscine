#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "Animal.hpp"
# include <iostream>
# include <string>

class WrongCat : public WrongAnimal
{
	public:
		// Constructors
		WrongCat();
		WrongCat(const WrongCat &copy);
		
		// Destructor
		~WrongCat();
		
		// Operators
		WrongCat & operator=(const WrongCat &assign);
		
		void	makeSound() const;

	private:
		
};

#endif