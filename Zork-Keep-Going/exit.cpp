#include "exit.h"


Exit::Exit(const std::string name, const std::string description, Room * origin, std::string orientation, 
	std::string destination, bool locked, Item * item)
	: Entity(name,description,origin) {
}

Exit::~Exit() {
}

Exit * Exit::Find(std::string name)
{
	return this;
}
