#ifndef __FRAGTRAP__
#define __FRAGTRAP__

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{

public:
	FragTrap(std::string name);
	FragTrap(const FragTrap& frag);
	~FragTrap();
	FragTrap&	operator = (const FragTrap &frag);

	void	highFivesGuys(void);
};

#endif

