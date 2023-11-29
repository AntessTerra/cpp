#ifndef __FRAGTRAP__
#define __FRAGTRAP__

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{

protected:
	const int _deffHp;
	const int _deffEp;
	const int _deffAd;

public:
	FragTrap(std::string name);
	FragTrap(const FragTrap& frag);
	~FragTrap();
	FragTrap&	operator = (const FragTrap &frag);

	void	highFivesGuys(void);
};

#endif

