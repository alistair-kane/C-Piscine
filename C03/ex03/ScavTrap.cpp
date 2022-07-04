#include "ScavTrap.hpp"

// Constructors
ScavTrap::ScavTrap(ScavTrap const &copy) : ClapTrap(copy._Name)
{
	this->_hit_points = copy.get_hit_points();
	this->_energy_points = copy.get_energy_points();
	this->_attack_damage = copy.get_attack_damage();
	std::cout << "\e[0;33mCopy Constructor called of ScavTrap\e[0m" << std::endl;
}

ScavTrap::ScavTrap(std::string _Name) : ClapTrap(_Name)
{
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
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