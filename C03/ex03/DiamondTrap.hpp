#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <iostream>
# include <string>
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap
{
	public:
		// Constructors
		DiamondTrap(DiamondTrap const &copy);
		DiamondTrap(std::string _Name);
		DiamondTrap & operator=(DiamondTrap const & input);
		// Destructor
		~DiamondTrap();

		void	whoAmI();

	private:
		std::string	_Name;

};

#endif