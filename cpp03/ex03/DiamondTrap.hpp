#ifndef __DIAMONDTRAP__
#define __DIAMONDTRAP__

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
protected:
	std::string	_name;

public:
	DiamondTrap(std::string name);
	DiamondTrap(const DiamondTrap& diamond);
	virtual	~DiamondTrap();
	DiamondTrap&	operator = (const DiamondTrap &diamond);

	using	ScavTrap::attack;
	void	whoAmI();
};

#endif

