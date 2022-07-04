#include "ClapTrap.hpp"

// Constructors
ClapTrap::ClapTrap()
{
	_Name = "";
	_hit_points = 10;
	_energy_points = 10;
	_attack_damage = 0;
	std::cout << "\e[0;33mDefault Constructor called of ClapTrap\e[0m" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &copy)
{
	_Name = copy._Name;
	_hit_points = copy._hit_points;
	_energy_points = copy._energy_points;
	_attack_damage = copy._attack_damage;
	std::cout << "\e[0;33mCopy Constructor called of ClapTrap\e[0m" << std::endl;
}

ClapTrap::ClapTrap(std::string _Name)
{
	this->_Name = _Name;
	_hit_points = 10;
	_energy_points = 10;
	_attack_damage = 0;
	std::cout << "\e[0;33mFields Constructor called of ClapTrap\e[0m" << std::endl;
}

// Destructor
ClapTrap::~ClapTrap()
{
	std::cout << "\e[0;31mDestructor called of ClapTrap\e[0m" << std::endl;
}

// Getters / Setters

std::string	ClapTrap::get_Name(void) const
{
	return(this->_Name);
}

unsigned int	ClapTrap::get_attack_damage(void) const
{
	return(this->_attack_damage);
}

unsigned int	ClapTrap::get_energy_points(void) const
{
	return(this->_energy_points);
}

unsigned int	ClapTrap::get_hit_points(void) const
{
	return(this->_hit_points);
}

// Member functions

void	ClapTrap::attack(const std::string& target)
{
	if (_hit_points <= 0)
		std::cout << "ClapTrap is dead, thus unable to attack"<< std::endl;
	else if (_energy_points <= 0)
		std::cout << "ClapTrap has no energy, thus unable to attack"<< std::endl;
	else
	{
	std::cout 
		<< "ClapTrap "
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

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hit_points <= 0)
		std::cout << "ClapTrap is already dead, thus cannot endure more pain"<< std::endl;
	else
	{
	std::cout 
		<< "ClapTrap "
		<< _Name
		<< " takes "
		<< amount
		<< " points of damage!"
		<< std::endl;
	}
	_hit_points -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_hit_points <= 0)
		std::cout << "ClapTrap is already dead, thus cannot be repaired"<< std::endl;
	else if (_energy_points <= 0)
		std::cout << "ClapTrap has no energy, thus unable to be repaired"<< std::endl;
	else
	{
	std::cout 
		<< "ClapTrap "
		<< _Name
		<< " takes "
		<< amount
		<< " points of repair!"
		<< std::endl;
	}
	_hit_points += amount;
	_energy_points--;
}

std::string	ClapTrap::name(std::string name)
{
	return(name += "_clap_name");
}