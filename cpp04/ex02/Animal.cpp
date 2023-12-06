#include "Animal.hpp"

AAnimal::AAnimal(){
	std::cout << "Creating a default AAnimal!!" << std::endl;
	_type = "Generic";
	return ;
}

AAnimal::AAnimal(const AAnimal& ani){
	*this = ani;
	std::cout << "Copied properties from another AAnimal!!" << std::endl;
	return ;
}

AAnimal::~AAnimal(){
	std::cout << "Erasing an AAnimal!!" << std::endl;
	return ;
}

AAnimal& AAnimal::operator = (const AAnimal& ani){
	_type = ani.getType();
	return (*this);
}

void	AAnimal::makeSound(void) const{
	std::cout << "What does the fox say?? No really." << std::endl;
	return ;
}

std::string	AAnimal::getType(void) const{
	return (_type);
}

