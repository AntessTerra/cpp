#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main(void){
	std::cout << "CREATING A NEW MATERIA SOURCE!!\n\n";
	IMateriaSource* src = new MateriaSource();

	std::cout << "\nLEARNING 4 MATERIAS!!\n\n";
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());

	std::cout << "\nFAILING TO LEARN ANOTHER 2 MATERIAS!!\n\n";
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());

	std::cout << "\nCREATING CHARACTER ME!!\n\n";
	ICharacter* me = new Character("me");

	std::cout << "\nCREATING AND EQUIPING 2 MATERIAS FROM SOURCE TEMPLATE!!\n\n";
	AMateria* tmp;
	AMateria* toDelete;
	tmp = src->createMateria("ice");
	toDelete = tmp;
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	std::cout << "\nFAILING TO CREATE MATERIA FROM SOURCE TEMPLATE!!\n\n";
	tmp = src->createMateria("unidentified");
	me->equip(tmp);

	std::cout << "\nCREATING CHARACTER BOB!!\n\n";
	ICharacter* bob = new Character("bob");

	std::cout << "\nUSING EQUIPED MATERIAS FROM ME CHARACTER ON BOB!!\n\n";
	me->use(0, *bob);
	me->use(1, *bob);

	std::cout << "\nFAILING TO USE A MATERIA ON BOB!!\n\n";
	me->use(2, *bob);

	std::cout << "\nUNEQUIPING A MATERIA AND FAILING TO USE IT ON BOB!!\n\n";
	me->unequip(0);
	me->use(0, *bob);

	std::cout << "\nDELETING EVERYTHING!!\n\n";
	delete bob;
	delete me;
	delete src;
	delete toDelete;

	return 0;
}
