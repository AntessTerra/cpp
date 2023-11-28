#ifndef __SCAVTRAP__
#define __SCAVTRAP__

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{

protected:
	const int _deffHp;
	const int _deffEp;
	const int _deffAd;

public:
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap& scav);
	~ScavTrap();
	ScavTrap&	operator = (const ScavTrap &scav);

	void	guardGate();
	void	attack(const std::string& target);
};

#endif

