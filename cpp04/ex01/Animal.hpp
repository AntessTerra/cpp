#ifndef __ANIMAL__
#define __ANIMAL__

#include <iostream>

class Animal
{
protected:
	std::string	_type;
public:
	Animal();
	Animal(const Animal& ani);
	virtual	~Animal();
	Animal& operator = (const Animal& ani);

	virtual void		makeSound(void) const;
	virtual std::string	getType(void) const;
};

#endif
