#include "Character.hpp"

Character::Character(std::string name): _name(name){
	std::cout << "Creating a new Character with name " << name << " !!" << std::endl;
	for (int i = 0; i < 4; i++)
		_inv[i] = NULL;
	return ;
}

Character::Character(const Character& ch){
	std::cout << "Copying from a Character!!" << std::endl;
	_name = ch._name;
	for (int i = 0; i < 4; i++)
		if (_inv[i] != NULL)
			delete _inv[i];
	for (int i = 0; i < 4; i++)
		if (ch._inv[i] != NULL)
			_inv[i] = ch._inv[i]->clone();
	return ;
}

Character::~Character(){
	std::cout << "Deleting a Character!!" << std::endl;
	for (int i = 0; i < 4; i++)
		if (_inv[i] != NULL)
			delete _inv[i];
	return ;
}

Character&Character::operator = (const Character& ch){
	std::cout << "Copy & assign from a Character!!" << std::endl;
	_name = ch._name;
	for (int i = 0; i < 4; i++)
		if (_inv[i] != NULL)
			delete _inv[i];
	for (int i = 0; i < 4; i++)
		if (ch._inv[i] != NULL)
			_inv[i] = ch._inv[i]->clone();
	return (*this);
}

std::string const& Character::getName() const{
	return (_name);
}

void Character::equip(AMateria* m){
	if (m == NULL)
		return (std::cout << "Character " << getName() << " cannot equip this wrong Materia!!" << std::endl, (void) 0);
	for (size_t i = 0; i < 4; i++){
		if (_inv[i] == NULL){
			_inv[i] = m;
			break ;
		}
	}
	std::cout << "Character " << getName() << " has equiped a new Materia of type " << m->getType() << std::endl;
	return ;
}

void Character::unequip(int idx){
	std::cout << "Character " << getName() << " is unequiping Materia of type " << _inv[idx]->getType() << std::endl;
	_inv[idx] = NULL;
	return ;
}

void Character::use(int idx, ICharacter& target){
	if (_inv[idx] == NULL)
		return (std::cout << "Cannot use Materia at an empty slot!!" << std::endl, (void) 0);
	_inv[idx]->use(target);
	return ;
}
