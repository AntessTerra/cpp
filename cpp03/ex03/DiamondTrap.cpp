#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name"), FragTrap(ClapTrap::_name), ScavTrap(ClapTrap::_name){
	_name = name;
	_hp = FragTrap::_deffHp;
	_ep = ScavTrap::_deffEp;
	_ad = FragTrap::_deffAd;
	#if !GRAPHICS
		std::cout << "DiamondTrap " << _name << " says: Now it's weird!" << std::endl;
	#else
		logs << "DiamondTrap " << _name << " says: Now it's weird!" << std::endl;
		image.str(std::string());
		image << CONSTRUCTOR;
	#endif
	return ;
}

DiamondTrap::~DiamondTrap(){
	#if !GRAPHICS
		std::cout << "DiamondTrap " << _name << " says: Shutting down!" << std::endl;
	#else
		logs << "DiamondTrap " << _name << " says: Shutting down!" << std::endl;
		image.str(std::string());
		image << DESTRUCTOR;
	#endif
	return ;
}

void	DiamondTrap::whoAmI(){
	#if !GRAPHICS
		std::cout << "DiamondTrap WHOAMI?? My name: " << _name << " and clap name: " << ClapTrap::_name << std::endl;
	#else
		logs << "DiamondTrap WHOAMI?? My name: " << _name << " and clap name: " << ClapTrap::_name << std::endl;
	#endif
	return ;
}

DiamondTrap::DiamondTrap(const DiamondTrap& diamond): ClapTrap(diamond._name + "_clap_name"), FragTrap(diamond._name), ScavTrap(diamond._name){
	*this = diamond;
	return ;
}

DiamondTrap&	DiamondTrap::operator = (const DiamondTrap &diamond){
	_name = diamond._name;
	_hp = diamond._hp;
	_ep = diamond._ep;
	_ad = diamond._ad;
	return (*this);
}
