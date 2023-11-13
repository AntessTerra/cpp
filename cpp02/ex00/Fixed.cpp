#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed(): _val(0){
	std::cout << "\e[0;32m✔ Default constructor called\e[0m" << std::endl;
	return ;
}

Fixed::Fixed(const Fixed &fixed){
	std::cout << "\e[0;34m© Copy constructor called\e[0m" << std::endl;
	*this = fixed;
}

Fixed::~Fixed(){
	std::cout << "\e[0;30m🔨 Destructor called\e[0m" << std::endl;
	return ;
}

Fixed& Fixed::operator = (const Fixed &fixed){
	std::cout << "\e[0;35m➡ Copy assignment operator called\e[0;30m" << std::endl;
	_val = fixed.getRawBits();
	return (*this);
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
