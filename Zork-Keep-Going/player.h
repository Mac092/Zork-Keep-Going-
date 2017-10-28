#ifndef PLAYER_C
#define PLAYER_C

#include "entity.h"
#include "character.h"
#include <string>

class Player : public Character
{
public:
	Player(const std::string name, const std::string description, int lifePoints, int attack,
		std::map<std::string,int> inventory, bool isAlive, Weapon* currentWeaponk, Room* room);
	~Player();

};

#endif // !PLAYER_C