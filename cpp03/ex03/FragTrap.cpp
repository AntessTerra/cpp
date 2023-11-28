#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name): ClapTrap(name), _deffHp(100), _deffEp(100), _deffAd(30){
	_name = name;
	_hp = _deffHp;
	_ep = _deffEp;
	_ad = _deffAd;
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

FragTrap::FragTrap(const FragTrap& Frag): ClapTrap(Frag._name), _deffHp(100), _deffEp(100), _deffAd(30){
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
