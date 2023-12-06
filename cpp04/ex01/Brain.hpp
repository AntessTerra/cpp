#ifndef __BRAIN__
#define __BRAIN__

#include <iostream>

class Brain
{
private:
	std::string _ideas[100];
public:
	Brain();
	Brain(const Brain& brain);
	~Brain();
	Brain&  operator = (const Brain& brain);
};

#endif
