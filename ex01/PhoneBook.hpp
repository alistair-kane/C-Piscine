#ifndef	PHONEBOOK
#define	PHONEBOOK

#include "Contact.hpp"
#include <string>
#include <iostream>

class PhoneBook 
{
	PhoneBook(void);

	public:
		void	add_entry(void);
		void	search_entry(void);

	private:
		static const size_t	max_contacts = 8;
		Contact				contacts[max_contacts];
		size_t				current_index;
		void				add_entry(Contact& c);
};

#endif