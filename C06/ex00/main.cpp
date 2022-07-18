/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkane <alkane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 18:38:48 by alkane            #+#    #+#             */
/*   Updated: 2022/07/17 19:09:51 by alkane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConversion.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Please provide 1 argument" << std::endl;
        return 1;
    }
    
    // type of cast?
    std::string input = argv[1];
}