#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
	public:
		// Constructors
		FragTrap();
		FragTrap(FragTrap const &copy);
		FragTrap(std::string _Name);

		// Destructor
		~FragTrap();

		void	highFivesGuys();
};

#endif