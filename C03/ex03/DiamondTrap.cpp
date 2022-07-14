#include "DiamondTrap.hpp"

// Constructors

DiamondTrap::DiamondTrap(DiamondTrap const &copy) : ClapTrap(copy._Name + "_clap_name"), ScavTrap(copy._Name + "_clap_name"), FragTrap(copy._Name + "_clap_name")
{
	*this = copy;
	std::cout << "\e[0;33mCopy Constructor called of DiamondTrap\e[0m" << std::endl;
}

DiamondTrap::DiamondTrap(std::string _Name) : ClapTrap(_Name + "_clap_name"), ScavTrap(_Name + "_clap_name"), FragTrap(_Name + "_clap_name")
{
	this->_Name = _Name;
	this->_hit_points = FragTrap::default_hitpoints;
	this->_energy_points = ScavTrap::default_energyPoints;
	this->_attack_damage = FragTrap::default_attackDamage;
	std::cout << "\e[0;33mFields Constructor called of DiamondTrap\e[0m" << std::endl;
}

DiamondTrap & DiamondTrap::operator=(DiamondTrap const & input)
{
	this->_Name = input._Name;
	this->_hit_points = input._hit_points;
	this->_energy_points = input._energy_points;
	this->_attack_damage = input._attack_damage;
	return (*this);
}

// Destructor
DiamondTrap::~DiamondTrap()
{
	std::cout << "\e[0;31mDestructor called of DiamondTrap\e[0m" << std::endl;
}

void	DiamondTrap::whoAmI()
{
	std::cout << "My name is:" << _Name << std::endl;
	std::cout << "My ClapTrap name is:" << ClapTrap::name(_Name) << std::endl;


}