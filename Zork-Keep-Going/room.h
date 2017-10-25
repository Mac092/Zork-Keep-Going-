#ifndef ROOM
#define ROOM

#include "entity.h"
#include <string>

class Room : public Entity
{
public:
	Room(const std::string name, const std::string description, Entity *PARENT = nullptr);
	~Room();

	virtual Room* Find(std::string name);

};
#endif
