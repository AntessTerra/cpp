#ifndef __CAT__
#define __CAT__

#include "Animal.hpp"

class Cat : public Animal
{
public:
	Cat();
	Cat(const Cat& cat);
	~Cat();
	Cat& operator = (const Cat& cat);

	void		makeSound(void) const;
	std::string	getType(void) const;
};

class WrongCat : public WrongAnimal
{
public:
	WrongCat();
	WrongCat(const WrongCat& wrong);
	~WrongCat();
	WrongCat& operator = (const WrongCat& wrong);

	void		makeSound(void) const;
	std::string	getType(void) const;
};

#endif
