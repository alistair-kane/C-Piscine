#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include <string>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	public:
		// Constructors
		Cat();
		Cat(const Cat &copy);
		
		// Destructor
		~Cat();
		
		// Operators
		Cat & operator=(const Cat &assign);
		
		void		makeSound() const;
		void		setIdeas(unsigned int index, const std::string idea) const;
		std::string	getIdeas(unsigned int index) const;

	private:
		Brain	*brain;
};

#endif