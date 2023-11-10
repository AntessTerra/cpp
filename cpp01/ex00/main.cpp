#include "Zombie.hpp"

int main(void)
{
	randomChump("FILIP");

	Zombie *z = newZombie("ANDREI");
	z->announce();
	delete z;
}
