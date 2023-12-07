#include "AMateria.hpp"

AMateria::AMateria(std::string const& type): _type(type){
	std::cout << "Creating a new Materia!!" << std::endl;
	return ;
}

AMateria::AMateria(const AMateria& materia){
	std::cout << "Copying from a Materia!!" << std::endl;
	if (_type == materia._type)
		return ;
	return ;
}

AMateria::~AMateria(){
	std::cout << "Deleting a Materia!!" << std::endl;
	return ;
}

AMateria& AMateria::operator = (const AMateria& materia){
	std::cout << "Copy & assign from a Materia!!" << std::endl;
	if (_type == materia._type)
		return (*this);
	return (*this);
}

std::string const& AMateria::getType() const{
	return (_type);
}

void AMateria::use(ICharacter& target){
	std::cout << "* uses blank Materia on " << target.getName() << " *" << std::endl;
	return ;
}
