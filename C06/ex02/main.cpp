/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkane <alkane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 14:10:44 by alkane            #+#    #+#             */
/*   Updated: 2022/07/23 14:38:50 by alkane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"

Base* generate(void)
{
	Base *pointer;

    std::srand (std::time(0));
	if (std::rand() % 3 == 0)
    {
        pointer = new A();
    }
    else if (std::rand() % 3 == 1)
    {
        pointer = new B();
        
    }
    else if (std::rand() % 3 == 2)
    {
        pointer = new C();
    }
    return pointer;
}

