#include "FragTrap.hpp"

// Constructors
FragTrap::FragTrap()
{
	set_Name("");
	set_hit_points(100);
	set_energy_points(100);
	set_attack_damage(30);
	std::cout << "\e[0;33mDefault Constructor called of FragTrap\e[0m" << std::endl;
}

FragTrap::FragTrap(FragTrap const &copy) : ClapTrap(copy._Name)
{
	set_hit_points(copy._hit_points);
	set_energy_points(copy._energy_points);
	set_attack_damage(copy._attack_damage);
	std::cout << "\e[0;33mCopy Constructor called of FragTrap\e[0m" << std::endl;
}

FragTrap::FragTrap(std::string _Name)
{
	set_Name(_Name);
	set_hit_points(100);
	set_energy_points(100);
	set_attack_damage(30);
	std::cout << "\e[0;33mFields Constructor called of FragTrap\e[0m" << std::endl;
}

// Destructor
FragTrap::~FragTrap()
{
	std::cout << "\e[0;31mDestructor called of FragTrap\e[0m" << std::endl;
}

// Member functions

void	FragTrap::highFivesGuys()
{
	if (_hit_points <= 0)
		std::cout << "FragTrap is dead, thus unable to request high fives"<< std::endl;
	else
	{
		std::cout
			<< "FragTrap "
			<< _Name
			<< " is now requesting positive high fives"
			<< std::endl;
	}
}