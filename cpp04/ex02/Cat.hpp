#ifndef __CAT__
#define __CAT__

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
private:
	Brain*		_brain;
public:
	Cat();
	Cat(const Cat& cat);
	~Cat();
	Cat& operator = (const Cat& cat);

	void		makeSound(void) const;
	std::string	getType(void) const;

	void		compareCats(const Cat& other);
};

#endif
