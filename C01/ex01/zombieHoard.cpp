/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHoard.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alistair <alistair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 22:36:02 by alistair          #+#    #+#             */
/*   Updated: 2022/06/24 01:48:24 by alistair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#include <new>

Zombie*	zombieHoard(int N, std::string name)
{
	Zombie* hoard = new Zombie[N];

	for (int i = 0; i < N; i++)
		hoard[i].set_name(name);
	return (hoard);
}
