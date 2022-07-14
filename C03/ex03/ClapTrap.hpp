#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{
	public:
		// Constructors
		ClapTrap();
		ClapTrap(ClapTrap const &copy);
		ClapTrap & operator=(ClapTrap const & input);
		ClapTrap(std::string _Name);

		// Destructor
		~ClapTrap();

		// Getters / Setters
		std::string		get_Name(void) const;
		unsigned int	get_hit_points(void) const;
		unsigned int	get_energy_points(void) const;
		unsigned int	get_attack_damage(void) const;

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		static std::string	name(std::string name);

	protected:
		std::string		_Name;
		unsigned int	_hit_points;
		unsigned int	_energy_points;
		unsigned int	_attack_damage;
		
};

#endif