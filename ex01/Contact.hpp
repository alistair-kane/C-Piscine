#ifndef	CONTACT
#define	CONTACT

#include <string>

class Contact 
{
	public:
		bool		set_first_name(std::string first_name);
		bool		set_last_name(std::string last_name);
		bool		set_nickname(std::string nickname);
		bool		set_phone_number(std::string phone_number);
		bool		set_darkest_secret(std::string darkest_secret);

		std::string	get_first_name(void);
		std::string	get_last_name(void);
		std::string	get_nickname(void);
		std::string	get_phone_number(void);
		std::string	get_darkest_secret(void);

	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;
};

typedef bool	(Contact::* contact_setters)(std::string);
typedef std::string(Contact::* contact_getters)(void);

#endif