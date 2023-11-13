#include <iostream>
#include <sstream>
#include "Fixed.hpp"

Fixed::Fixed(): _val(0){
	std::cout << "\e[0;32m✔ Default constructor called\e[0m" << std::endl;
	return ;
}

Fixed::Fixed(const int num): _val(num){
	std::cout << "\e[0;33m↩ Int constructor called\e[0m" << std::endl;
	return ;
}

Fixed::Fixed(const float num){
	std::cout << "\e[0;34m↪ Float constructor called\e[0m" << std::endl;
	// std::string	s, t;
	// std::stringstream	ss;
	// ss << num;
	// s = ss.str();
	// t = s.substr(s.find(".") + 1);
	// _val = (num >> t.length());
	float	test = num;
	while ((int)test % 10 > 0){
		std::cout << (int)test << std::endl;
		test = (test * 10);
	}
	return ;
}

Fixed::Fixed(const Fixed &fixed){
	std::cout << "\e[0;35m© Copy constructor called\e[0m" << std::endl;
	*this = fixed;
}

Fixed::~Fixed(){
	std::cout << "\e[0;30m🔨 Destructor called\e[0m" << std::endl;
	return ;
}

Fixed& Fixed::operator = (const Fixed &fixed){
	std::cout << "\e[0;36m➡ Copy assignment operator called\e[0;30m" << std::endl;
	_val = fixed._val;
	return (*this);
}

std::ostream&	operator << (std::ostream& out, const Fixed &fixed){
	std::stringstream	ss;
	std::string			str;
	ss << fixed.toFloat();
	ss >> str;
	out << str;
	return (out);
}

int		Fixed::getRawBits(void) const{
	std::cout << "\e[0;31m❤ getRawBits member function called\e[0m" << std::endl;
	return (_val);
}

void	Fixed::setRawBits(int const raw){
	std::cout << "✒ setRawBits member function called" << std::endl;
	_val = raw;
	return ;
}

float	Fixed::toFloat(void) const{
	return ((float)_val);
}

int	Fixed::toInt(void) const{
	return ((int)_val);
}
