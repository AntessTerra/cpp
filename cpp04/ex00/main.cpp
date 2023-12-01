#include "Cat.hpp"
#include "Dog.hpp"

int main(void){
	{
		const Animal	*meta = new Animal();

		meta->makeSound();

		delete(meta);
		std::cout << std::endl;
	}
	{
		const Animal	*c = new Cat();

		std::cout << "Animal type: " << c->getType() << " " << std::endl;
		c->makeSound();

		delete(c);
		std::cout << std::endl;
	}
	{
		const Animal	*d = new Dog();

		std::cout << "Animal type: " << d->getType() << " " << std::endl;
		d->makeSound();

		delete(d);
		std::cout << std::endl;
	}
	{
		const WrongAnimal	*wc = new WrongCat();

		std::cout << "Animal type: " << wc->getType() << " " << std::endl;
		wc->makeSound();

		delete(wc);
		std::cout << std::endl;
	}

	return (0);
}
