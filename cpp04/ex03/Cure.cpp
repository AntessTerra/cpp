#include "Cure.hpp"

Cure::Cure(): AMateria("cure"){
	std::cout << "Creating a new Cure!!" << std::endl;
	return ;
}

Cure::Cure(const Cure& cure): AMateria("cure"){
	std::cout << "Copying from Cure!!" << std::endl;
	if (_type == cure._type)
		return ;
	return ;
}

Cure::~Cure(){
	std::cout << "Poisoning Cure!!" << std::endl;
	return ;
}

Cure& Cure::operator = (const Cure& cure){
	std::cout << "Copy & addign from Cure!!" << std::endl;
	if (_type == cure._type)
		return (*this);
	return (*this);
}

AMateria* Cure::clone(){
	AMateria* cure = new Cure();
	return (cure);
}

void Cure::use(ICharacter& target){
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
	return ;
}
