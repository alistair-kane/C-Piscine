#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap
{
	public:
		// Constructors
		ScavTrap(std::string _Name);
		ScavTrap(ScavTrap const &copy);
		ScavTrap & operator=(ScavTrap const & input);

		// Destructor
		~ScavTrap();

		virtual void	attack(const std::string& target);
		void			guardGate();

	protected:
		static unsigned int const	default_hitpoints = 100;
		static unsigned int const	default_energyPoints = 50;
		static unsigned int const	default_attackDamage = 20;
};

#endif