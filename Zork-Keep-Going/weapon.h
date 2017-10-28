#pragma once
#include "item.h"

class Weapon: public Item
{
public:
	Weapon(std::string name, std::string description, int power, Entity* parent);
	~Weapon();
};

