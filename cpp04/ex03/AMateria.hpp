#ifndef __AMATERIA__
#define __AMATERIA__

#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
protected:
	std::string	_type;
public:
	AMateria(std::string const& type);
	AMateria(const AMateria& materia);
	virtual ~AMateria();
	AMateria& operator = (const AMateria& materia);

	std::string const& getType() const;

	virtual AMateria* clone() = 0;
	virtual void use(ICharacter& target);
};

#endif
