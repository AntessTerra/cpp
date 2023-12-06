#include "Cat.hpp"
#include "Dog.hpp"

int main(void){
	// AAnimal test;

	std::cout << "CREATING AN ABSTRACT FARM!!\n\n";
	size_t	N = 2;
	const	AAnimal*	farm[N];

	for (size_t i = 0; i < N; i++){
		if (i < N/2)
			farm[i] = new Dog();
		else
			farm[i] = new Cat();
	}
	std::cout << "\nABSTRACT ANIMALS MAKING NOISE!!\n\n";
	for (size_t i = 0; i < N; i++){
		farm[i]->makeSound();
	}

	std::cout << "\nDELETING AN ABSTRACT FARM!!\n\n";
	for (size_t i = 0; i < N; i++){
		delete farm[i];
	}

	std::cout << "\nCREATING A CAT AND A DEEP COPY!!\n\n";
	Cat*	cat = new Cat();
	Cat*	deep = new Cat(*cat);

	std::cout << "\nCOMPARING A CAT AND A DEEP COPY!!\n\n";
	cat->compareCats(*deep);

	std::cout << "\nDELETING A CAT AND A DEEP COPY!!\n\n";
	delete cat;
	delete deep;

	return (0);
}
