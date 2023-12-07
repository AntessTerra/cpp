#ifndef __CURE__
#define __CURE__

#include "AMateria.hpp"

class Cure : public AMateria
{
public:
	Cure();
	Cure(const Cure& cure);
	~Cure();
	Cure& operator = (const Cure& cure);

	AMateria* clone();
	void use(ICharacter& target);
};

#endif
