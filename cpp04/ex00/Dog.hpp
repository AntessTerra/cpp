#ifndef __DOG__
#define __DOG__

#include "Animal.hpp"

class Dog : public Animal
{
public:
	Dog();
	Dog(const Dog& dog);
	~Dog();
	Dog& operator = (const Dog& dog);

	void		makeSound(void) const;
	std::string	getType(void) const;
};

#endif
