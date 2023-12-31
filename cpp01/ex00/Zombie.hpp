#ifndef __ZOMBIE__
#define __ZOMBIE__

#include <iostream>

class Zombie
{
private:
	std::string	_name;
public:
	Zombie(std::string name);
	~Zombie();

	void	announce(void);
};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

#endif
