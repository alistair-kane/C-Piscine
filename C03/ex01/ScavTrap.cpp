#include "ScavTrap.hpp"

// Constructors
ScavTrap::ScavTrap()
{
	_Name = "";
	_hit_points = 100;
	_energy_points = 50;
	_attack_damage = 20;
	std::cout << "\e[0;33mDefault Constructor called of ScavTrap\e[0m" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &copy)
{
	_Name = copy._Name;
	_hit_points = copy._hit_points;
	_energy_points = copy._energy_points;
	_attack_damage = copy._attack_damage;
	std::cout << "\e[0;33mCopy Constructor called of ScavTrap\e[0m" << std::endl;
}

ScavTrap::ScavTrap(std::string _Name)
{
	this->_Name = _Name;
	_hit_points = 100;
	_energy_points = 50;
	_attack_damage = 20;
	std::cout << "\e[0;33mFields Constructor called of ScavTrap\e[0m" << std::endl;
}

// Destructor
ScavTrap::ScavTrap()
{
	std::cout << "\e[0;31mDestructor called of ScavTrap\e[0m" << std::endl;
}

// Member functions

void	ScavTrap::attack(const std::string& target)
{
	if (_hit_points <= 0)
		std::cout << "ScavTrap is dead, thus unable to attack"<< std::endl;
	else if (_energy_points <= 0)
		std::cout << "ScavTrap has no energy, thus unable to attack"<< std::endl;
	else
	{
	std::cout 
		<< "ScavTrap "
		<< _Name
		<< " attacks "
		<< target
		<< ", causing "
		<< _attack_damage
		<< " points of damage!"
		<< std::endl;
	}
	_energy_points--;
}

ScavTrap::ScavTrap(std::string _Name)
{
	this->_Name = _Name;
	_hit_points = 100;
	_energy_points = 50;
	_attack_damage = 20;
	std::cout << "\e[0;33mFields Constructor called of ScavTrap\e[0m" << std::endl;
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