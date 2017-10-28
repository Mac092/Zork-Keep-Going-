#include "weapon.h"


Weapon::Weapon(std::string name, std::string description, int power, Entity * parent)
:Item(name,description,parent) {
}

Weapon::~Weapon()
{
}
