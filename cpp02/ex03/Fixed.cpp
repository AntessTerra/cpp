#include <iostream>
#include <sstream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed(): _val(0){
	// std::cout << "\e[0;32m✔ Default constructor called\e[0m" << std::endl;
	return ;
}

Fixed::Fixed(const int num){
	// std::cout << "\e[0;33m↩ Int constructor called\e[0m" << std::endl;
	_val = num << _fracBits;
	return ;
}

Fixed::Fixed(const float num){
	// std::cout << "\e[0;34m↪ Float constructor called\e[0m" << std::endl;
	_val = (roundf(num * (1 << _fracBits)));
	return ;
}

Fixed::Fixed(const Fixed &fixed){
	// std::cout << "\e[0;35m© Copy constructor called\e[0m" << std::endl;
	*this = fixed;
}

Fixed::~Fixed(){
	// std::cout << "\e[0;30m🔨 Destructor called\e[0m" << std::endl;
	return ;
}

Fixed& Fixed::operator = (const Fixed &fixed){
	// std::cout << "\e[0;36m➡ Copy assignment operator called\e[0;30m" << std::endl;
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
	// std::cout << "\e[0;31m❤ getRawBits member function called\e[0m" << std::endl;
	return (_val);
}

void	Fixed::setRawBits(int const raw){
	// std::cout << "✒ setRawBits member function called" << std::endl;
	_val = raw;
	return ;
}

float	Fixed::toFloat(void) const{
	return (((float)_val) / (1 << _fracBits));
}

int	Fixed::toInt(void) const{
	return (_val >> _fracBits);
}

int	Fixed::operator > (const Fixed &fixed) const{
	if (this->getRawBits() > fixed.getRawBits())
		return (1);
	return (0);
}

int	Fixed::operator < (const Fixed &fixed) const{
	if (this->getRawBits() > fixed.getRawBits())
		return (1);
	return (0);
}
int	Fixed::operator >= (const Fixed &fixed) const{
	if (this->getRawBits() >= fixed.getRawBits())
		return (1);
	return (0);
}

int	Fixed::operator <= (const Fixed &fixed) const{
	if (this->getRawBits() <= fixed.getRawBits())
		return (1);
	return (0);
}

int	Fixed::operator == (const Fixed &fixed) const{
	if (this->getRawBits() == fixed.getRawBits())
		return (1);
	return (0);
}

int	Fixed::operator != (const Fixed &fixed) const{
	if (this->getRawBits() != fixed.getRawBits())
		return (1);
	return (0);
}

Fixed	Fixed::operator + (const Fixed &fixed) const{
	Fixed	out(this->toFloat() + fixed.toFloat());

	return (out);
}

Fixed	Fixed::operator - (const Fixed &fixed) const{
	Fixed	out(this->toFloat() - fixed.toFloat());

	return (out);
}

Fixed	Fixed::operator * (const Fixed &fixed) const{
	Fixed	out(this->toFloat() * fixed.toFloat());

	return (out);
}

Fixed	Fixed::operator / (const Fixed &fixed) const{
	Fixed	out(this->toFloat() / fixed.toFloat());

	return (out);
}

Fixed&	Fixed::operator ++ (){
	this->_val += 1;
	return (*this);
}

Fixed&	Fixed::operator -- (){
	this->_val -= 1;
	return (*this);
}

Fixed	Fixed::operator ++ (int n){
	(void)n;
	Fixed	tmp = *this;

	this->_val += 1;
	return (tmp);
}

Fixed	Fixed::operator -- (int n){
	(void)n;
	Fixed	tmp = *this;

	this->_val -= 1;
	return (tmp);
}

Fixed&	Fixed::min(Fixed &one, Fixed &other){
	if (one < other)
		return (one);
	return (other);
}

Fixed&	Fixed::max(Fixed &one, Fixed &other){
	if (one > other)
		return (one);
	return (other);
}

const Fixed&	Fixed::min(const Fixed &one, const Fixed &other){
	if (one < other)
		return (one);
	return (other);
}

const Fixed&	Fixed::max(const Fixed &one, const Fixed &other){
	if (one > other)
		return (one);
	return (other);
}
