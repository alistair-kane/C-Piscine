#ifndef	HARL
#define HARL

#include <cstring>
#include <string>
#include <iostream>

enum	msg_levels { DEBUG, INFO, WARNING, ERROR};

class Harl
{
	public:
		Harl(){};
		~Harl()
		{
			// std::cout << "Weapon " << type << " destroyed" << std::endl;
		};
		void		complain(std::string level);
	
	private:
		void		debug(void);
		void		info(void);
		void		warning(void);
		void		error(void);
};

typedef	void	(Harl::* HarlMemberFuncs)(void);

#endif