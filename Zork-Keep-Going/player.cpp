#include "player.h"
#include "entity.h"



Player::Player(const std::string name, const std::string description, int lifePoints, int attack,
	std::map<std::string, int> inventory, bool isAlive, Weapon * currentWeapon, Room * room)
	:Character(name,description,lifePoints,attack,inventory,isAlive,currentWeapon,room)
{
}

Player::~Player() {
}
