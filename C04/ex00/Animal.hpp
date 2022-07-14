#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal
{
	public:
		// Constructors
		Animal();
		Animal(const Animal &copy);
		
		// Destructor
		~Animal();
		
		// Operators
		Animal & operator=(const Animal &assign);
		
		// Getter
		std::string	getType() const;
		void		makeSound() const;

	protected:
		std::string	type;
		
};

#endif