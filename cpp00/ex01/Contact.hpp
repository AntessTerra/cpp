#ifndef __CONTACT__
#define __CONTACT__

#include <iostream>
class Contact
{
private:
	int			_index;
	std::string	_firstName, _lastName, _nickname, _darkestSecret, _phoneNumber;

public:
	Contact();

	Contact(int index, std::string first_name, std::string last_name,
		std::string nickname, std::string darkest_secret,
		std::string phone_number);

	Contact& operator=(const Contact& other);

	~Contact();

	int	getIndex();
	std::string	getPhone();
	std::string	getFirstName();
	std::string	getLastName();
	std::string	getNickname();
	std::string	getSecret();

};

#endif
