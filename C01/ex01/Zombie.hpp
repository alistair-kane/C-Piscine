#ifndef	ZOMBIE
#define	ZOMBIE

#include <string>
#include <iostream>

class Zombie
{
	public:
		Zombie(){};
		~Zombie(void)
		{
			std::cout << "Zombie " << name << " destroyed" << std::endl;
		};

		void	announce(void);
		void	set_name(std::string first_name);

	private:
		std::string	name;
};

Zombie*	zombieHoard(int N, std::string name);

#endif