#include "Zombie.hpp"

Zombie::Zombie(std::string name){
	_name = name;
	return ;
}

Zombie::~Zombie(){
	std::cout << "Killing zombie " << _name << std::endl;
	return ;
}

void	Zombie::announce(){
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	return ;
}


