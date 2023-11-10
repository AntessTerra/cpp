#ifndef __PHONEBOOK__
#define __PHONEBOOK__

#include "Contact.hpp"

class PhoneBook
{
private:
	Contact	_contacts[8];
	int		_lastAdded;

	std::string	truncate(std::string str, int width);
	std::string	getValueFromUser(std::string message);
	bool is_digits(const std::string &str);
	void	print(int i);

public:
	PhoneBook();

	void	addContact();
	void	printAll();
	void	printAtString(std::string str);
	void	printAtNum(int n);

	~PhoneBook();
};

#endif
