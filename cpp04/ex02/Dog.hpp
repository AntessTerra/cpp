#ifndef __DOG__
#define __DOG__

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
private:
	Brain*	_brain;
public:
	Dog();
	Dog(const Dog& dog);
	~Dog();
	Dog& operator = (const Dog& dog);

	void		makeSound(void) const;
	std::string	getType(void) const;
};

#endif
