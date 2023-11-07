#include <iostream>
#include <sstream>
#include <iomanip>

class Contact
{
private:
	int			_index;
	std::string	_first_name, _last_name, _nickname, _darkest_secret, _phone_number;

public:
	Contact(int index = 0, std::string first_name = "", std::string last_name = "",
		std::string nickname = "", std::string darkest_secret = "",
		std::string phone_number = "")
		: _index(index), _first_name(first_name), _last_name(last_name),
		_nickname(nickname), _darkest_secret(darkest_secret),
		_phone_number(phone_number)
	{
	}

	Contact& operator=(const Contact& other) {
		this->_index = other._index;
		this->_first_name = other._first_name;
		this->_last_name = other._last_name;
		this->_nickname = other._nickname;
		this->_darkest_secret = other._darkest_secret;
		this->_phone_number = other._phone_number;
		return *this;
	}

	int	getIndex()
	{
		return (_index);
	}

	std::string	getPhone()
	{
		return (_phone_number);
	}

	std::string	getFirstName()
	{
		return (_first_name);
	}

	std::string	getLastName()
	{
		return (_last_name);
	}

	std::string	getNickname()
	{
		return (_nickname);
	}

	std::string	getSecret()
	{
		return (_darkest_secret);
	}

};


