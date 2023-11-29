#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name): _name(name), _hp(10), _ep(10), _ad(0){
	#if !GRAPHICS
		std::cout << "ClapTrap " << _name << " says: Aaaaand... OPEN!" << std::endl;
	#else
		logs << "ClapTrap " << _name << " says: Aaaaand... OPEN!" << std::endl;
		image.str(std::string());
		image << CONSTRUCTOR;
	#endif
	return ;
}

ClapTrap::~ClapTrap(){
	#if !GRAPHICS
		std::cout << "ClapTrap " << _name << " says: Shutting down!" << std::endl;
	#else
		logs << "ClapTrap " << _name << " says: Shutting down!" << std::endl;
		image.str(std::string());
		image << DESTRUCTOR;
	#endif
	return ;
}

ClapTrap::ClapTrap(const ClapTrap& clap){
	*this = clap;
	return ;
}

ClapTrap&	ClapTrap::operator = (const ClapTrap &clap){
	_name = clap._name;
	_hp = clap._hp;
	_ep = clap._ep;
	_ad = clap._ad;
	return (*this);
}

void	ClapTrap::attack(const std::string& target){
	if (_ep > 0)
	{
		_ep -= 1;
		#if !GRAPHICS
			std::cout << "ClapTrap " << _name << " attacks " << target << ", causing "
			<< getAttackDamage() << " points of damage!" << std::endl;
		#else
			logs << "ClapTrap " << _name << " attacks " << target << ", causing "
			<< getAttackDamage() << " points of damage!" << std::endl;
		#endif

	}
	else
		#if !GRAPHICS
			std::cout << "ClapTrap " << _name << " doesn't have enough energy to preform ATTACK action!!" << std::endl;
		#else
			logs << "ClapTrap " << _name << " doesn't have enough energy to preform ATTACK action!!" << std::endl;
		#endif
	return ;
}

void	ClapTrap::takeDamage(unsigned int amount){
	_hp -= amount;
	#if !GRAPHICS
		std::cout << "ClapTrap " << _name << " takes " << amount << " damage!" << std::endl;
	#else
		logs << "ClapTrap " << _name << " takes " << amount << " damage!" << std::endl;
	#endif

	return ;
}

void	ClapTrap::beRepaired(unsigned int amount){
	if (_ep > 0)
	{
		_ep -= 1;
		_hp += amount;
		#if !GRAPHICS
			std::cout << "ClapTrap " << _name << " is repared by " << amount << " hit points." << std::endl;
		#else
			logs << "ClapTrap " << _name << " is repared by " << amount << " hit points." << std::endl;
		#endif
	}
	else
		#if !GRAPHICS
			std::cout << "ClapTrap " << _name << " doesn't have enough energy to preform REPAIR action!!" << std::endl;
		#else
			logs << "ClapTrap " << _name << " doesn't have enough energy to preform REPAIR action!!" << std::endl;
		#endif
	return ;
}

std::string	ClapTrap::getName() const{
	return (_name);
}

int	ClapTrap::getHitPoints() const{
	return (_hp);
}

int	ClapTrap::getEnergyPoints() const{
	return (_ep);
}

int	ClapTrap::getAttackDamage() const{
	return (_ad);
}

