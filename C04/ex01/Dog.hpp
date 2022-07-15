#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include <string>
# include "Animal.hpp"
# include "Brain.hpp"
class Dog : public Animal
{
	public:
		// Constructors
		Dog();
		Dog(const Dog &copy);
		
		// Destructor
		~Dog();
		
		// Operators
		Dog & operator=(const Dog &assign);

		void		makeSound() const;
		void		setIdeas(unsigned int index, const std::string idea) const;
		std::string	getIdeas(unsigned int index) const;

	private:
		Brain	*brain;
		
};

#endif