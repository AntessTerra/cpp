#include "Serializer.hpp"

int main(void){
	Data data;
	data.id = 42;
	data.name = "42 PRAGUE";

	std::cout << "\e[33m" << data.id << "\e[0m: \e[32m" << data.name << "\e[0m\nPointer: \e[34m" << &data << "\e[0m\n" << std::endl;

	std::cout << "\e[35m ⚙️ SERIALIZING ⚙️ \e[0m" << std::endl;
	uintptr_t raw = Serializer::serialize(&data);

	std::cout << "Raw Pointer: \e[34m" << &raw << "\e[0m\n" << std::endl;

	std::cout << "\e[35m ⚙️ DESERIALIZING ⚙️ \e[0m" << std::endl;
	Data* back = Serializer::deserialize(raw);

	std::cout << "\e[33m" << back->id << "\e[0m: \e[32m" << back->name << "\e[0m\nBack Pointer: \e[34m" << back << "\e[0m == \e[34m" << &data << "\e[0m :Data Pointer" << std::endl;
}
