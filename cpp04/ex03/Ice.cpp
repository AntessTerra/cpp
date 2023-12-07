#include "Ice.hpp"

Ice::Ice(): AMateria("ice"){
	std::cout << "Creating a new Ice!!" << std::endl;
	return ;
}

Ice::Ice(const Ice& ice): AMateria("ice"){
	std::cout << "Copying from Ice!!" << std::endl;
	if (_type == ice._type)
		return ;
	return ;
}

Ice::~Ice(){
	std::cout << "Melting Ice!!" << std::endl;
	return ;
}

Ice& Ice::operator = (const Ice& ice){
	std::cout << "Copy & addign from Ice!!" << std::endl;
	if (_type == ice._type)
		return (*this);
	return (*this);
}

AMateria* Ice::clone(){
	AMateria* ice = new Ice();
	return (ice);
}

void Ice::use(ICharacter& target){
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	return ;
}
