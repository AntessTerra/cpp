#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name): _name(name){
	std::cout << "Aaaaand... OPEN!" << std::endl << std::endl;
	std::cout << CONSTRUCTOR << std::endl;
	return ;
}

ClapTrap::ClapTrap(const ClapTrap& clap){
	*this = clap;
	return ;
}

ClapTrap::~ClapTrap(){
	std::cout << "Shutting down!" << std::endl << std::endl;
	std::cout << DESTRUCTOR << std::endl;
	return ;
}

ClapTrap&	ClapTrap::operator = (const ClapTrap &clap){
	_name = clap._name;
	return (*this);
}
