#ifndef __ICE__
#define __ICE__

#include "AMateria.hpp"

class Ice : public AMateria
{
public:
	Ice();
	Ice(const Ice& ice);
	~Ice();
	Ice& operator = (const Ice& ice);

	AMateria* clone();
	void use(ICharacter& target);
};

#endif
