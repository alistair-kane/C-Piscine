/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkane <alkane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 13:25:49 by alkane            #+#    #+#             */
/*   Updated: 2022/06/17 13:41:07 by alkane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

bool	Contact::set_first_name(std::string first_name)
{
	// checks that can return false

	this->first_name = first_name;
	return true;
}

bool	Contact::set_last_name(std::string last_name)
{
	// checks that can return false

	this->last_name = last_name;
	return true;
}

bool	Contact::set_nickname(std::string nickname)
{
	// checks that can return false

	this->nickname = nickname;
	return true;
}

bool	Contact::set_phone_number(std::string phone_number)
{
	// checks that can return false

	this->phone_number = phone_number;
	return true;
}

bool	Contact::set_darkest_secret(std::string darkest_secret)
{
	// checks that can return false

	this->darkest_secret = darkest_secret;
	return true;
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