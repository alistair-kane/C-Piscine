/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkane <alkane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 13:25:49 by alkane            #+#    #+#             */
/*   Updated: 2022/06/23 04:01:41 by alkane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

static bool	check_input_alpha(std::string input)
{
	std::locale loc;

	if (input.length() == 0)
	{
		std::cerr << "Please input letters" << std::endl;
		return (false);
	}
	for (std::string::iterator it=input.begin(); it!=input.end(); ++it)
  	{
    	if (std::isalpha(*it,loc) == false)
		{
			std::cerr << "Please use alphabetical input" << std::endl;
			return (false);
		}
	}
	return (true);
}

bool	Contact::set_first_name(std::string first_name)
{
	if (check_input_alpha(first_name) == true)
	{
		this->first_name = first_name;
		return (true);
	}
	return (false);
}

bool	Contact::set_last_name(std::string last_name)
{
	if (check_input_alpha(last_name) == true)
	{
		this->last_name = last_name;
		return (true);
	}
	return (false);
}

bool	Contact::set_nickname(std::string nickname)
{
	if (check_input_alpha(nickname) == true)
	{
		this->nickname = nickname;
		return (true);
	}
	return (false);
}

bool	Contact::set_phone_number(std::string phone_number)
{
	if (phone_number.length() == 0)
	{
		std::cerr << "Please input something" << std::endl;
		return (false);
	}
	this->phone_number = phone_number;
	return true;
}

bool	Contact::set_darkest_secret(std::string darkest_secret)
{
	if (check_input_alpha(darkest_secret) == true)
	{
		this->darkest_secret = darkest_secret;
		return (true);
	}
	return (false);
}

std::string	Contact::get_first_name(void) {
	return (this->first_name); }

std::string	Contact::get_last_name(void) {
	return (this->last_name); }

std::string	Contact::get_nickname(void) {
	return (this->nickname); }

std::string	Contact::get_phone_number(void) {
	return (this->phone_number); }

std::string	Contact::get_darkest_secret(void) {
	return (this->darkest_secret); }