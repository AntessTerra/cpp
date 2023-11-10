#include <iostream>
#include <sstream>
#include <iomanip>
#include "Contact.hpp"

Contact::Contact(){
	return ;
}

Contact::Contact(int index, std::string first_name, std::string last_name,
	std::string nickname, std::string darkest_secret,
	std::string phone_number)
	: _index(index), _firstName(first_name), _lastName(last_name),
	_nickname(nickname), _darkestSecret(darkest_secret),
	_phoneNumber(phone_number){
}

Contact& Contact::operator=(const Contact& other) {
	this->_index = other._index;
	this->_firstName = other._firstName;
	this->_lastName = other._lastName;
	this->_nickname = other._nickname;
	this->_darkestSecret = other._darkestSecret;
	this->_phoneNumber = other._phoneNumber;
	return *this;
}

Contact::~Contact(){
	return ;
}

int	Contact::getIndex(){
	return (_index);
}

std::string	Contact::getPhone(){
	return (_phoneNumber);
}

std::string	Contact::getFirstName()
{
	return (_firstName);
}

std::string	Contact::getLastName()
{
	return (_lastName);
}

std::string	Contact::getNickname()
{
	return (_nickname);
}

std::string	Contact::getSecret()
{
	return (_darkestSecret);
}
