#ifndef __MATERIASOURCE__
#define __MATERIASOURCE__

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
protected:
	AMateria	*_memory[4];
public:
	MateriaSource();
	MateriaSource(const MateriaSource& source);
	~MateriaSource();
	MateriaSource& operator = (const MateriaSource& source);

	void learnMateria(AMateria*);
	AMateria* createMateria(std::string const & type);
};

#endif
