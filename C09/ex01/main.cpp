/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alistair <alistair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:52:13 by alistair          #+#    #+#             */
/*   Updated: 2023/05/10 20:48:39 by alistair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv) 
{
    try
    {   
        RPN rpn(argc, argv);
    }
    catch (std::exception & err) 
    {
        std::cerr << err.what() << std::endl;
    }
    return 0;
}
