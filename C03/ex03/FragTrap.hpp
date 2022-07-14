#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap
{
	public:
		// Constructors
		FragTrap(FragTrap const &copy);
		FragTrap(std::string _Name);
		FragTrap & operator=(FragTrap const & input);
		// Destructor
		~FragTrap();

		void	highFivesGuys();
	
	protected:
		static unsigned int const	default_hitpoints = 100;
		static unsigned int const	default_energyPoints = 100;
		static unsigned int const	default_attackDamage = 30;

};

#endif