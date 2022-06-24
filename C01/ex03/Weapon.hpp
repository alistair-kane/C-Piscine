#ifndef	WEAPON
#define WEAPON

#include <string>
#include <iostream>

class Weapon
{
	public:
		Weapon(std::string _type): type(_type) {};
		~Weapon(void)
		{
			// std::cout << "Weapon " << type << " destroyed" << std::endl;
		};

		const std::string&	getType(void);
		void	            setType(std::string new_type);

	private:
		std::string	type;
};

#endif