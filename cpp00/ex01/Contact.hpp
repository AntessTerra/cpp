#include <iostream>
#include <sstream>
#include <iomanip>

class Contact
{
private:
	int			_index;
	std::string	_firstName, _lastName, _nickname, _darkestSecret, _phoneNumber;

public:
	Contact(int index = 0, std::string first_name = "", std::string last_name = "",
		std::string nickname = "", std::string darkest_secret = "",
		std::string phone_number = "")
		: _index(index), _firstName(first_name), _lastName(last_name),
		_nickname(nickname), _darkestSecret(darkest_secret),
		_phoneNumber(phone_number)
	{
	}

	Contact& operator=(const Contact& other) {
		this->_index = other._index;
		this->_firstName = other._firstName;
		this->_lastName = other._lastName;
		this->_nickname = other._nickname;
		this->_darkestSecret = other._darkestSecret;
		this->_phoneNumber = other._phoneNumber;
		return *this;
	}

	int	getIndex()
	{
		return (_index);
	}

	std::string	getPhone()
	{
		return (_phoneNumber);
	}

	std::string	getFirstName()
	{
		return (_firstName);
	}

	std::string	getLastName()
	{
		return (_lastName);
	}

	std::string	getNickname()
	{
		return (_nickname);
	}

	std::string	getSecret()
	{
		return (_darkestSecret);
	}

};


