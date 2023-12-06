#include "Brain.hpp"

Brain::Brain(){
	std::cout << "Creating a default Brain!!" << std::endl;
	for (int i = 0; i < 100; i++)
		_ideas[i] = "";
	return ;
}

Brain::Brain(const Brain& brain){
	for (int i = 0; i < 100; i++)
		_ideas[i] = brain._ideas[i];
	std::cout << "Copying ideas from another Brain!!" << std::endl;
	return ;
}

Brain::~Brain(){
	std::cout << "Destroying a Brain!!" << std::endl;
	return ;
}

Brain&  Brain::operator = (const Brain& brain){
	for (int i = 0; i < 100; i++)
		_ideas[i] = brain._ideas[i];
	return (*this);
}
