#include "Cat.hpp"

Cat::Cat(){
	std::cout << "Creating a default Cat!!" << std::endl;
	_type = "Cat";
	_brain = new Brain();
	return ;
}

Cat::Cat(const Cat& cat){
	_brain = new Brain(*cat._brain);
	std::cout << "Copied properties from another Cat!!" << std::endl;
	return ;
}

Cat::~Cat(){
	std::cout << "Erasing a Cat!!" << std::endl;
	delete _brain;
	return ;
}

Cat& Cat::operator = (const Cat& cat){
	_type = cat.getType();
	_brain = new Brain(*cat._brain);
	return (*this);
}

void	Cat::makeSound(void) const{
	std::cout << "Cat goes \"meow\"" << std::endl;
	return ;
}

std::string	Cat::getType(void) const{
	return (_type);
}

void	Cat::compareCats(const Cat &other){
	std::cout << "This cat adress " << &(this->_brain) << std::endl;
	std::cout << "Others cat adress " << &(other._brain) << std::endl;
}
