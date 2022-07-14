#ifndef	HUMANA
#define HUMANA

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanA
{
	public:
		HumanA(std::string _name, Weapon& _weapon) : name(_name), weapon(_weapon) {};
		~HumanA(void){};

		void    attack(void);

	private:
		std::string	name;
		Weapon&		weapon;
};

#endif