#include "Contact.hpp"

class PhoneBook
{
private:
	Contact	_contacts[8];
	int		_lastAdded;

	std::string	truncate(std::string str, int width)
	{
		if ((int)str.length() > width)
		{
			str.resize(width);
			return (str + ".");
		}
		return (str);
	}

	std::string	getValueFromUser(std::string message)
	{
		std::string	out;

		std::cout << message << std::endl;
		std::getline(std::cin, out);
		return (out);
	}

	bool is_digits(const std::string &str) {
		return str.find_first_not_of("0123456789") == std::string::npos;
}

	void	print(int i)
	{
		std::cout << std::setw(10) << std::setprecision(10) << i % 8 << "|" <<
		std::setw(10) << truncate(_contacts[i].getFirstName(), 9) << "|" <<
		std::setw(10) << truncate(_contacts[i].getLastName(), 9) << "|" <<
		std::setw(10) << truncate(_contacts[i].getNickname(), 9) << std::endl;
	}

public:
	PhoneBook()
	{
		_lastAdded = -1;
		// std::cout << "Contact created" << std::endl;
	}

	void	addContact()
	{
		std::string	firstName, lastName, nickname, darkestSecret, phone;

		firstName = getValueFromUser("Enter first name: ");
		while (firstName.length() <= 0)
			firstName = getValueFromUser("ERROR: Enter first name: ");

		lastName = getValueFromUser("Enter last name: ");
		while (lastName.length() <= 0)
			lastName = getValueFromUser("ERROR: Enter last name: ");

		nickname = getValueFromUser("Enter nickname: ");
		while (nickname.length() <= 0)
			nickname = getValueFromUser("ERROR: Enter nickname: ");

		darkestSecret = getValueFromUser("Enter your darkest secret: ");
		while (darkestSecret.length() <= 0)
			darkestSecret = getValueFromUser("ERROR: Enter your darkest secret: ");

		phone = getValueFromUser("Enter phonenumber: ");
		while (phone.length() <= 3 || is_digits(phone) == 0)
			phone = getValueFromUser("ERROR: Enter phonenumber: ");


		_lastAdded = _lastAdded + 1;
		if (_lastAdded == 8)
			_lastAdded = 0;
		_contacts[_lastAdded] = Contact(_lastAdded, firstName, lastName, nickname, darkestSecret, phone);
		std::cout << "Successfully added contact" << std::endl;
	}

	void	printAll()
	{
		for (int i = 0; i < 8 && _contacts[i].getFirstName().compare(""); i++)
			print(i);
	}

	void	printAtString(std::string str)
	{
		for (int i = 0; i < 8 && _contacts[i].getFirstName().length() > 0; i++)
		{
			if (!_contacts[i].getFirstName().compare(str))
				print(i);
			else if (!_contacts[i].getLastName().compare(str))
				print(i);
			else if (!_contacts[i].getNickname().compare(str))
				print(i);
			else if (!_contacts[i].getSecret().compare(str))
				print(i);
		}
	}

	void	printAtNum(int n)
	{
		if (n < 8 && n >= 0 && _contacts[n].getFirstName().length() > 0)
			print(n);
		else if (n > 8 || n < 0)
		{
			std::stringstream ss;
			ss << n;
			std::string number;
			ss >> number;
			for (int i = 0; i < 8 && _contacts[i].getPhone().length() > 0; i++)
				if (!_contacts[i].getPhone().compare(number))
					print(i);
		}
	}

	~PhoneBook()
	{
		// std::cout << "Contact destroyed" << std::endl;
	}
};
