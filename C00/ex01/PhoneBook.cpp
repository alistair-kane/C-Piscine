/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkane <alkane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 18:47:52 by alkane            #+#    #+#             */
/*   Updated: 2022/06/24 17:35:17 by alkane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

// template function designed to accept int/long/size_t values and return their string equivalent
template<typename T>
std::string to_string(const T & value) 
{
    std::ostringstream oss;

    oss << value;
    return (oss.str());
}

// constructor of Phonebook class, passing -1 in initialization list to current_index
PhoneBook::PhoneBook(void) : pos(-1), maxed(false){}

static int stoi(std::string& s)
{
    int i;

    std::istringstream(s) >> i;
    return (i);
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
	int	insert_pos; 
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

	this->pos = this->pos == -1 ? 0 : this->pos;
	insert_pos = this->pos % this->max_contacts;
	for (int i = 0; i < 5; i++)
		(this->contacts[insert_pos].*setters[i])((c.*getters[i])());
	this->pos++;
	if (this->pos == this->max_contacts)
	{
		this->pos = 0;
		this->maxed = true;
	}
	std::cout << "Contact added at position: " << insert_pos << std::endl;
}

void	PhoneBook::search_entry(void)
{
	int	index;
	
	if (this->pos == -1)
		std::cout << "Phonebook is currently empty!" << std::endl;
	else
	{
		print_header();
		for (int i = 0; i < this->max_contacts; i++)
		{
			truncate_print_string(to_string(i), 1);
			truncate_print_string(this->contacts[i].get_first_name(), 1);
			truncate_print_string(this->contacts[i].get_last_name(), 1);
			truncate_print_string(this->contacts[i].get_nickname(), 0);
		}
		if (index_from_user_input(index, this->pos) == true)
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

void	PhoneBook::print_full_details(int index)
{
	std::cout << "First Name: " << this->contacts[index].get_first_name() << std::endl;
	std::cout << "Last Name: " << this->contacts[index].get_last_name() << std::endl;
	std::cout << "Nickname: " << this->contacts[index].get_nickname() << std::endl;
	std::cout << "Phone Number: " << this->contacts[index].get_phone_number() << std::endl;
	std::cout << "Darkest Secret: " << this->contacts[index].get_darkest_secret() << std::endl;
}

bool	PhoneBook::index_from_user_input(int &index, int limit)
{
	std::string input;
	int			index_input = -1;
	int			attempts = 0;
	
	if (limit == 0 || (limit == 1 && this->maxed == true))
		limit = this->max_contacts;
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
		if (index_input >= 0 && index_input < limit)
		{
			index = index_input;
			return (true);
		}
		std::cerr << "Index must be between 0 and " << limit - 1 << std::endl;
	}
	std::cerr << "Too many failed attempts" << std::endl;
	return (false);
}
