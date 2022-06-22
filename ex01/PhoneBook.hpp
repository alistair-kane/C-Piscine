#ifndef	PHONEBOOK
#define	PHONEBOOK

#include "Contact.hpp"
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>

class PhoneBook 
{
	public:
		PhoneBook(void);
		// ~PhoneBook(void);
		void	add_entry(void);
		void	search_entry(void);

	private:
		static const size_t	max_contacts = 8;
		Contact				contacts[max_contacts];
		size_t				current_index;
		void				add_entry(Contact& c);
	
	void	print_header(void);
	void	print_short_details(size_t index);
	void	print_full_details(size_t index);
	bool	index_from_user_input(size_t *index, size_t max);
};

#endif