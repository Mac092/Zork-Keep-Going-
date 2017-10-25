#ifndef PLAYER_C
#define PLAYER_C

#include "entity.h"
#include <string>

class Player : public Entity
{
public:
	Player(const std::string name, const std::string description, Entity *PARENT = nullptr);
	~Player();

};

#endif // !PLAYER_C