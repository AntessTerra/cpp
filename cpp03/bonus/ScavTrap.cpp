#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name): ClapTrap(name), _deffHp(100), _deffEp(50), _deffAd(20){
	_name = name;
	_hp = _deffHp;
	_ep = _deffEp;
	_ad = _deffAd;
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

ScavTrap::ScavTrap(const ScavTrap& scav): ClapTrap(scav._name), _deffHp(100), _deffEp(50), _deffAd(20){
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
