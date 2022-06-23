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

		void	add_entry(void);
		void	search_entry(void);

	private:
		
		static const int	max_contacts = 8;
		Contact				contacts[max_contacts];
		int					pos;
	
		void				add_entry(Contact& c);
		void				print_header(void);
		void				print_full_details(int index);
		bool				index_from_user_input(int *index, int max);
};

#endif