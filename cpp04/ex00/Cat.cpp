#include "Cat.hpp"

Cat::Cat(){
	std::cout << "Creating a default Cat!!" << std::endl;
	_type = "Cat";
	return ;
}

Cat::Cat(const Cat& cat){
	*this = cat;
	std::cout << "Copied properties from another Cat!!" << std::endl;
	return ;
}

Cat::~Cat(){
	std::cout << "Erasing a Cat!!" << std::endl;
	return ;
}

Cat& Cat::operator = (const Cat& cat){
	_type = cat.getType();
	return (*this);
}

void	Cat::makeSound(void) const{
	std::cout << "Cat goes \"meow\"" << std::endl;
	return ;
}

std::string	Cat::getType(void) const{
	return (_type);
}


WrongCat::WrongCat(){
	std::cout << "Creating a default WrongCat!!" << std::endl;
	_type = "WrongCat";
	return ;
}

WrongCat::WrongCat(const WrongCat& wrong){
	*this = wrong;
	std::cout << "Copied properties from another WrongCat!!" << std::endl;
	return ;
}

WrongCat::~WrongCat(){
	std::cout << "Erasing a WrongCat!!" << std::endl;
	return ;
}

WrongCat& WrongCat::operator = (const WrongCat& wrong){
	_type = wrong.getType();
	return (*this);
}

void	WrongCat::makeSound(void) const{
	std::cout << "WrongCat goes \"monster noice\"" << std::endl;
	return ;
}

std::string	WrongCat::getType(void) const{
	return (_type);
}
