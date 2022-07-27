#include "FragTrap.hpp"

// Constructors
FragTrap::FragTrap(FragTrap const &copy) : ClapTrap(copy._Name)
{
	this->_hit_points = copy._hit_points;
	this->_energy_points = copy._energy_points;
	this->_attack_damage = copy._attack_damage;
	std::cout << "\e[0;33mCopy Constructor called of FragTrap\e[0m" << std::endl;
}

FragTrap::FragTrap(std::string _Name) : ClapTrap(_Name)
{
	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
	std::cout << "\e[0;33mFields Constructor called of FragTrap\e[0m" << std::endl;
}

FragTrap & FragTrap::operator=(FragTrap const & input)
{
	this->_Name = input._Name;
	this->_hit_points = input._hit_points;
	this->_energy_points = input._energy_points;
	this->_attack_damage = input._attack_damage;
	return (*this);
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