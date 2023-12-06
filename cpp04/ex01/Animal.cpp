#include "Animal.hpp"

Animal::Animal(){
	std::cout << "Creating a default Animal!!" << std::endl;
	_type = "Generic";
	return ;
}

Animal::Animal(const Animal& ani){
	*this = ani;
	std::cout << "Copied properties from another Animal!!" << std::endl;
	return ;
}

Animal::~Animal(){
	std::cout << "Erasing an Animal!!" << std::endl;
	return ;
}

Animal& Animal::operator = (const Animal& ani){
	_type = ani.getType();
	return (*this);
}

void	Animal::makeSound(void) const{
	std::cout << "What does the fox say?? No really." << std::endl;
	return ;
}

std::string	Animal::getType(void) const{
	return (_type);
}

