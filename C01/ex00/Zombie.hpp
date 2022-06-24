#ifndef	ZOMBIE
#define	ZOMBIE

#include <string>
#include <iostream>

class Zombie
{
	public:
		Zombie(const std::string _name) : name(_name) {};
		~Zombie(void)
		{
			std::cout << "Zombie " << name << " destroyed" << std::endl;
		};

		void	announce(void);

	private:
		std::string	name;
};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

#endif