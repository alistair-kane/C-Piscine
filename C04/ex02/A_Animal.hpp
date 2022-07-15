#ifndef A_ANIMAL_HPP
# define A_ANIMAL_HPP

# include <iostream>
# include <string>

class A_Animal
{
	public:
		// Constructors
		A_Animal();
		A_Animal(const A_Animal &copy);
		
		// Destructor
		virtual ~A_Animal();
		
		// Operators
		A_Animal & operator=(const A_Animal &assign);
		
		// Getter
		std::string		getType() const;

		virtual void	makeSound() const = 0;

	protected:
		std::string	type;
		
};

#endif