#include "Contact.hpp"

class PhoneBook
{
private:
	Contact	_contacts[8];
	int		_last_added;

	std::string	truncate(std::string str, int width)
	{
		if (str.length() > width)
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
		_last_added = -1;
		// std::cout << "Contact created" << std::endl;
	}

	void	addContact()
	{
		std::string	first_name, last_name, nickname, darkest_secret, phone;

		first_name = getValueFromUser("Enter first name: ");
		while (first_name.length() <= 0)
			first_name = getValueFromUser("ERROR: Enter first name: ");

		last_name = getValueFromUser("Enter last name: ");
		while (last_name.length() <= 0)
			last_name = getValueFromUser("ERROR: Enter last name: ");

		nickname = getValueFromUser("Enter nickname: ");
		while (nickname.length() <= 0)
			nickname = getValueFromUser("ERROR: Enter nickname: ");

		darkest_secret = getValueFromUser("Enter your darkest secret: ");
		while (darkest_secret.length() <= 0)
			darkest_secret = getValueFromUser("ERROR: Enter your darkest secret: ");

		phone = getValueFromUser("Enter phonenumber: ");
		while (phone.length() <= 3 || is_digits(phone) == 0)
			phone = getValueFromUser("ERROR: Enter phonenumber: ");


		_last_added = _last_added + 1;
		if (_last_added == 8)
			_last_added = 0;
		_contacts[_last_added] = Contact(_last_added, first_name, last_name, nickname, darkest_secret, phone);
		std::cout << "Added to index " << _last_added << std::endl;
	}

	void	printAll()
	{
		for (int i = 0; i < 8 && _contacts[i].getFirstName().compare(""); i++)
			print(i);
	}

	void	printAtNum(int n)
	{
		if (n < 8 && n >= 0 && _contacts[n].getFirstName().compare(""))
			print(n);
		else if (n > 8 || n < 0)
		{
			std::stringstream ss;
			ss << n;
			std::string number;
			ss >> number;
			for (int i = 0; _contacts[i].getPhone().length() > 0; i++)
				if (!_contacts[i].getPhone().compare(number))
					print(i);
		}
	}

	~PhoneBook()
	{
		// std::cout << "Contact destroyed" << std::endl;
	}
};
