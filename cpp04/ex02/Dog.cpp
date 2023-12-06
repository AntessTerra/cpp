#include "Dog.hpp"

Dog::Dog(){
	std::cout << "Creating a default Dog!!" << std::endl;
	_type = "Dog";
	_brain = new Brain();
	return ;
}

Dog::Dog(const Dog& dog){
	_brain = new Brain(*dog._brain);
	std::cout << "Copied properties from another Dog!!" << std::endl;
	return ;
}

Dog::~Dog(){
	std::cout << "Erasing a Dog!!" << std::endl;
	delete _brain;
	return ;
}

Dog& Dog::operator = (const Dog& dog){
	_type = dog.getType();
	_brain = new Brain(*dog._brain);
	return (*this);
}

void	Dog::makeSound(void) const{
	std::cout << "Dog goes \"woof\"" << std::endl;
	return ;
}

std::string	Dog::getType(void) const{
	return (_type);
}
