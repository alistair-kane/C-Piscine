/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkane <alkane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 18:47:52 by alkane            #+#    #+#             */
/*   Updated: 2022/06/20 16:01:19 by alkane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <string>

// constructor of Phonebook class, passing 0 in initialization list to current_index
PhoneBook::PhoneBook(void) : current_index(0){}

void	PhoneBook::add_entry(void)
{
	std::string	prompts[] = {
		"first name: ",
		"last name: ",
		"nickname: ",
		"phone number",
		"darkest secret"
	};
	contact_setters	setters[] = {
		&Contact::set_first_name,
		&Contact::set_last_name,
		&Contact::set_nickname,
		&Contact::set_phone_number,
		&Contact::set_darkest_secret
	};
	size_t		prompt_amt = 5;
	Contact		contact_to_add;
	std::string	input;
	bool		add_item = false;
	size_t		failed_entries = 0;
	size_t		i = 0;
	
	std::cout << "[ADD] Contact: Please provide details:" << std::endl;
	while(i < prompt_amt && failed_entries < 3)
	{
		std::cout << prompts[i];
		if (!(std::getline(std::cin, input)))
			input.clear();
		add_item = contact_to_add.set_first_name(input);
		if (add_item == false)
			failed_entries++;
		else
		{
			add_item = false;
			failed_entries = 0;
			i++;
		}
	}
	if (failed_entries != 0)
	{
		std::cerr << "Contact couldn't be added" << std::endl;
		return ;
	}
	this->add_entry(contact_to_add);
}

void	PhoneBook::add_entry(Contact& c)
{
	size_t	insert_pos = this->current_index % PhoneBook::max_contacts;
	contact_setters	setters[] = {
		&Contact::set_first_name,
		&Contact::set_last_name,
		&Contact::set_nickname,
		&Contact::set_phone_number,
		&Contact::set_darkest_secret
	};
	contact_getters getters[] = {
		&Contact::get_first_name,
		&Contact::get_last_name,
		&Contact::get_nickname,
		&Contact::get_phone_number,
		&Contact::get_darkest_secret
	};

	for (size_t i = 0; i < 5; i++)
		(this->contacts[insert_pos].*setters[i])((c.*getters[i])());
	this->current_index++;
	std::cout << "Contact added at position:" << insert_pos << std::endl;
}

void	PhoneBook::search_entry(void)
{
	size_t	index;
	
	if (current_index == 0)
		std::cout << "Phonebook is currently empty!" << std::endl;
	else
	{
		print_header();
		for (size_t i = 0; i < PhoneBook::max_contacts; i++)
			print_short_details(i);
		if (index_from_user_input(&index, this->current_index) == true)
			print_full_details(index - 1);
	}
}

bool	PhoneBook::index_from_user_input(size_t *index, size_t max)
{
	std::string input;
	int			index_input = -1;
	int			attempts = 0;
	
	while (attempts < 3)
	{
		std::cout << "Please enter contact by [index] to see more info: " << std::endl;
		if (!(std::getline(std::cin, input))
			input.clear();
		attempts++;
		try
			index_input = std::stoi(input, nullptr);
		catch (std::invalid_argument)
		{
			std::cerr << "Input invalid!" << std::endl;
			continue;
		}
		if (index_input > 0 && index_input <= (int)max))
		{
			*index = (size_t)index_input;
			return (true);
		}
		std::cerr << "Index must be between 0 and " << max << std::endl;
	}
	std::cerr << "Too many failed attempts" << std::endl;
	return (false);
}


