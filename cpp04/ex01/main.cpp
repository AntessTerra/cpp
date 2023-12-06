#include "Cat.hpp"
#include "Dog.hpp"

int main(void){
	std::cout << "CREATING A FARM!!\n\n";
	size_t	N = 2;
	const	Animal*	farm[N];

	for (size_t i = 0; i < N; i++){
		if (i < N/2)
			farm[i] = new Dog();
		else
			farm[i] = new Cat();
	}

	std::cout << "\nDELETING A FARM!!\n\n";
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

	std::cout << "\nCREATING A DOG!!\n\n";
	Dog basic;
	{
		std::cout << "\nCREATING A SHALLOW COPY!!\n\n";
		Dog tmp = basic;
		std::cout << "\nDESTROYING A SHALLOW COPY WITH ORIGINAL BRAIN!!\n\n";
	}
	std::cout << "\nTRYING TO DESTROY ORIGINAL DOG AND BRAIN AND FAILING!!\n\n";

	return (0);
}
