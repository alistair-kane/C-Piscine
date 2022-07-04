#include "ScavTrap.hpp"

// Constructors
ScavTrap::ScavTrap()
{
	set_Name("");
	set_hit_points(100);
	set_energy_points(50);
	set_attack_damage(20);
	std::cout << "\e[0;33mDefault Constructor called of ScavTrap\e[0m" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &copy) : ClapTrap(copy._Name)
{
	set_hit_points(copy._hit_points);
	set_energy_points(copy._energy_points);
	set_attack_damage(copy._attack_damage);
	std::cout << "\e[0;33mCopy Constructor called of ScavTrap\e[0m" << std::endl;
}

ScavTrap::ScavTrap(std::string _Name)
{
	set_Name(_Name);
	set_hit_points(100);
	set_energy_points(50);
	set_attack_damage(20);
	std::cout << "\e[0;33mFields Constructor called of ScavTrap\e[0m" << std::endl;
}

// Destructor
ScavTrap::~ScavTrap()
{
	// std::cout << "\e[0;31mDestructor called of ClapTrap ?\e[0m" << std::endl;
	std::cout << "\e[0;31mDestructor called of ScavTrap\e[0m" << std::endl;
}

// Member functions

void	ScavTrap::attack(const std::string& target)
{
	if (get_hit_points() <= 0)
		std::cout << "ScavTrap is dead, thus unable to attack"<< std::endl;
	else if (get_energy_points() <= 0)
		std::cout << "ScavTrap has no energy, thus unable to attack"<< std::endl;
	else
	{
	std::cout 
		<< "ScavTrap "
		<< get_Name()
		<< " attacks "
		<< target
		<< ", causing "
		<< get_attack_damage()
		<< " points of damage!"
		<< std::endl;
	}
	// _energy_points--;
}

void	ScavTrap::guardGate()
{
	if (_hit_points <= 0)
		std::cout << "ScavTrap is dead, thus unable to guard"<< std::endl;
	{   
	std::cout 
		<< "ScavTrap "
		<< _Name
		<< " is now in Gate Keeper mode "
		<< std::endl;
	}
}