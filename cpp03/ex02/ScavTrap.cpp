#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name): ClapTrap(name){
	_name = name;
	_hp = 100;
	_ep = 50;
	_ad = 20;
	#if !GRAPHICS
		std::cout << "ScavTrap " << _name << " says: Serena, my love!" << std::endl;
	#else
		logs << "ScavTrap " << _name << " says: Serena, my love!" << std::endl;
		image.str(std::string());
		image << CONSTRUCTOR;
	#endif
	return ;
}

ScavTrap::~ScavTrap(){
	#if !GRAPHICS
		std::cout << "ScavTrap " << _name << " says: Shutting down!" << std::endl;
	#else
		logs << "ScavTrap " << _name << " says: Shutting down!" << std::endl;
		image.str(std::string());
		image << DESTRUCTOR;
	#endif
	return ;
}

ScavTrap::ScavTrap(const ScavTrap& scav): ClapTrap(scav._name){
	*this = scav;
	return ;
}

ScavTrap&	ScavTrap::operator = (const ScavTrap &scav){
	_name = scav._name;
	_hp = scav._hp;
	_ep = scav._ep;
	_ad = scav._ad;
	return (*this);
}

void ScavTrap::guardGate(){
	#if !GRAPHICS
		std::cout << "ScavTrap " << _name << " is entering a Gate Keeper mode!" << std::endl;
	#else
		logs << "ScavTrap " << _name << " is entering a Gate Keeper mode!" << std::endl;
	#endif
	return ;
}

void	ScavTrap::attack(const std::string& target){
	if (_ep > 0)
	{
		_ep -= 1;
		#if !GRAPHICS
			std::cout << "ScavTrap " << _name << " attacks " << target << ", causing "
			<< getAttackDamage() << " points of damage!" << std::endl;
		#else
			logs << "ScavTrap " << _name << " attacks " << target << ", causing "
			<< getAttackDamage() << " points of damage!" << std::endl;
		#endif

	}
	else
		#if !GRAPHICS
			std::cout << "ScavTrap " << _name << " doesn't have enough energy to preform ATTACK action!!" << std::endl;
		#else
			logs << "ScavTrap " << _name << " doesn't have enough energy to preform ATTACK action!!" << std::endl;
		#endif
	return ;
}
