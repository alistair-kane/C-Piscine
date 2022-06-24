/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkane <alkane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 13:19:56 by alkane            #+#    #+#             */
/*   Updated: 2022/06/24 14:12:38 by alkane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	HUMANB
#define HUMANB

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanB
{
	public:
		HumanB(std::string _name) : name(_name)
		{
			weapon = NULL;
		};
		~HumanB(void){};

		void    attack(void);
        void    setWeapon(Weapon& _weapon);

	private:
		std::string name;
		Weapon      *weapon;
};

#endif