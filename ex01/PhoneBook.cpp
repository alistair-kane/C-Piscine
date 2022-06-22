/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkane <alkane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 18:47:52 by alkane            #+#    #+#             */
/*   Updated: 2022/06/21 19:19:49 by alkane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

// constructor of Phonebook class, passing 0 in initialization list to current_index
PhoneBook::PhoneBook(void) : current_index(0){}

static int stoi(std::string& s)
{
    int i;

    std::istringstream(s) >> i;
    return (i);
}

void	PhoneBook::add_entry(void)
{
	std::string	prompts[] = {
		"First Name: ",
		"Last Name: ",
		"Nickname: ",
		"Phone Number: ",
		"Darkest Secret: "
	};
	contact_setters	setters[] = {
		&Contact::set_first_name,
		&Contact::set_last_name,
		&Contact::set_nickname,
		&Contact::set_phone_number,
		&Contact::set_darkest_secret
	};
	Contact		contact_to_add;
	std::string	input;
	bool		add_item = false;
	size_t		failed_entries = 0;
	size_t		i = 0;
	
	std::cout << "[ADD] Contact: Please provide details:" << std::endl;
	while(i < 5 && failed_entries < 3)
	{
		std::cout << prompts[i];
		if (!(std::getline(std::cin, input)))
			input.clear();
		add_item = (contact_to_add.*setters[i])(input);
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
	std::cout << "Contact added at position: " << insert_pos << std::endl;
}

void	PhoneBook::search_entry(void)
{
	size_t	index;
	
	if (current_index == 0)
		std::cout << "Phonebook is currently empty!" << std::endl;
	else
	{
		print_header();
		for (size_t i = 0; i < this->max_contacts; i++)
			print_short_details(i);
		if (index_from_user_input(&index, this->current_index) == true)
			print_full_details(index);
	}
}

void	PhoneBook::print_header(void)
{
	std::string	headers[] = {
		"Index #",
		"First Name",
		"Last Name",
		"Nickname",
	};

	for (int i = 0; i < 4; i++)
	{
		std::cout << std::right << std::setw(10) << headers[i];
		if (i < 3)
			std::cout << "|";
	}
	std::cout << std::endl;
}

static void	truncate_print_string(std::string input, int divider)
{
	if (input.length() > 9)
	{
		input.resize(9);
		input.push_back('.');
	}
	std::cout << std::right << std::setw(10) << input;
	if (divider)
		std::cout << "|";
	else
		std::cout << std::endl;
}

void	PhoneBook::print_short_details(size_t index)
{
	std::cout << std::right << index << std::setw(10) << "|";
	// if (this->contacts[index].get_first_name().length() > 9)
		// std::cout << std::right << std::setw(9) << this->contacts[index].get_first_name() << "." << "|";
	// else
		// std::cout << std::right << std::setw(10) << this->contacts[index].get_first_name() << "|";
	truncate_print_string(this->contacts[index].get_first_name(), 1);
	truncate_print_string(this->contacts[index].get_last_name(), 1);
	truncate_print_string(this->contacts[index].get_nickname(), 0);	
	// if (this->contacts[index].get_last_name().length() > 9)
		// std::cout << std::right << std::setw(9) << this->contacts[index].get_last_name() << "." << "|";
	// else
		// std::cout << std::right << std::setw(10) << this->contacts[index].get_last_name() << "|";

	// if (this->contacts[index].get_nickname().length() > 9)
	// 	std::cout << std::right << this->contacts[index].get_nickname() << "." << std::setw(9);
	// else
	// 	std::cout << std::right << this->contacts[index].get_nickname() << std::setw(10);
	// std::cout << std::endl;
}

void	PhoneBook::print_full_details(size_t index)
{
	std::cout << "First Name: " << this->contacts[index].get_first_name() << std::endl;
	std::cout << "Last Name: " << this->contacts[index].get_last_name() << std::endl;
	std::cout << "Nickname: " << this->contacts[index].get_nickname() << std::endl;
	std::cout << "Phone Number: " << this->contacts[index].get_phone_number() << std::endl;
	std::cout << "Darkest Secret: " << this->contacts[index].get_darkest_secret() << std::endl;
}

bool	PhoneBook::index_from_user_input(size_t *index, size_t max)
{
	std::string input;
	int			index_input = -1;
	int			attempts = 0;
	
	while (attempts < 3)
	{
		std::cout << "Please enter a contact by index # to see more info: " << std::endl;
		if (!(std::getline(std::cin, input)))
			input.clear();
		attempts++;
		try
		{
			index_input = stoi(input);
		}
		catch (std::invalid_argument const&)
		{
			std::cerr << "Input invalid!" << std::endl;
			continue;
		}
		if (index_input >= 0 && index_input < (int)max)
		{
			*index = (size_t)index_input;
			return (true);
		}
		std::cerr << "Index must be between 0 and " << max - 1 << std::endl;
	}
	std::cerr << "Too many failed attempts" << std::endl;
	return (false);
}
