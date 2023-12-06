#ifndef __ANIMAL__
#define __ANIMAL__

#include <iostream>

class AAnimal
{
protected:
	std::string	_type;
public:
	AAnimal();
	AAnimal(const AAnimal& ani);
	virtual	~AAnimal();
	AAnimal& operator = (const AAnimal& ani);

	virtual void		makeSound(void) const = 0;
	virtual std::string	getType(void) const;
};

#endif
