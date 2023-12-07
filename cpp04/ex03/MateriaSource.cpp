#include "MateriaSource.hpp"
#include "Ice.hpp"

MateriaSource::MateriaSource(){
	std::cout << "Creating a new MateriaSource!!" << std::endl;
	for (int i = 0; i < 4; i++){
		_memory[i] = NULL;
	}
	return ;
}

MateriaSource::MateriaSource(const MateriaSource& source){
	std::cout << "Copying a new MateriaSource!!" << std::endl;
	for (int i = 0; i < 4; i++)
		if (_memory[i] != NULL)
			delete _memory[i];
	for (int i = 0; i < 4; i++)
		if (source._memory[i] != NULL)
			_memory[i] = source._memory[i]->clone();
	return ;
}

MateriaSource::~MateriaSource(){
	std::cout << "Destroying a MateriaSource!!" << std::endl;
	for (int i = 0; i < 4; i++)
		if (_memory[i] != NULL)
			delete _memory[i];
	return ;
}

MateriaSource& MateriaSource::operator = (const MateriaSource& source){
	std::cout << "Copy & assign a new MateriaSource!!" << std::endl;
	for (int i = 0; i < 4; i++)
		if (_memory[i] != NULL)
			delete _memory[i];
	for (int i = 0; i < 4; i++)
		if (source._memory[i] != NULL)
			_memory[i] = source._memory[i]->clone();
	return (*this);
}

void MateriaSource::learnMateria(AMateria* materia){
	int	added = 0;
	for (size_t i = 0; i < 4; i++){
		if (_memory[i] == NULL){
			_memory[i] = materia;
			added = 1;
			break ;
		}
	}
	if (!added){
		std::cout << "MateriaSource cannot learn any more Materia!!" << std::endl;
		delete materia;
	}
	return ;
}

AMateria* MateriaSource::createMateria(std::string const & type){
	for (int i = 0; i < 4; i++)
		if (_memory[i] != NULL && !type.compare(_memory[i]->getType()))
			return (_memory[i]->clone());
	std::cout << "MateriaSource couldn't create this Materia!!" << std::endl;
	return (0);
}
