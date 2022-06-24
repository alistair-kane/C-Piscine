/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkane <alkane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 12:10:13 by alkane            #+#    #+#             */
/*   Updated: 2022/06/24 13:12:26 by alkane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

void    HumanA::attack(void)
{
    std::cout << name << " attacks with their weapon " << weapon.getType() << std::endl;
}
