#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name): ClapTrap(name){
	_name = name;
	_hp = 100;
	_ep = 100;
	_ad = 30;
	#if !GRAPHICS
		std::cout << "FragTrap " << _name << " says: Repetitive work!" << std::endl;
	#else
		logs << "FragTrap " << _name << " says: Repetitive work!" << std::endl;
		image.str(std::string());
		image << CONSTRUCTOR;
	#endif
	return ;
}

FragTrap::~FragTrap(){
	#if !GRAPHICS
		std::cout << "FragTrap " << _name << " says: Shutting down!" << std::endl;
	#else
		logs << "FragTrap " << _name << " says: Shutting down!" << std::endl;
		image.str(std::string());
		image << DESTRUCTOR;
	#endif
	return ;
}

FragTrap::FragTrap(const FragTrap& Frag): ClapTrap(Frag._name){
	*this = Frag;
	return ;
}

FragTrap&	FragTrap::operator = (const FragTrap &Frag){
	_name = Frag._name;
	_hp = Frag._hp;
	_ep = Frag._ep;
	_ad = Frag._ad;
	return (*this);
}

void	FragTrap::highFivesGuys(void){
	#if !GRAPHICS
		std::cout << "FragTrap " << _name << " is doing the HighFive!" << std::endl;
	#else
		logs << "FragTrap " << _name << " is doing the HighFive!" << std::endl;
	#endif
	return ;
}
