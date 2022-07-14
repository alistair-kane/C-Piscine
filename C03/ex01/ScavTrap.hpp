#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
	public:
		// Constructors
		ScavTrap();
		ScavTrap(ScavTrap const &copy);
		ScavTrap(std::string _Name);

		// Destructor
		~ScavTrap();

		void	attack(const std::string& target);
		void	guardGate();
};

#endif