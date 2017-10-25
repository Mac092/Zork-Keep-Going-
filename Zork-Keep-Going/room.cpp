
#include "Room.h"

Room::Room(const std::string name, const std::string description, Entity * owner) : Entity(name, description, owner) {

	type = ENTITY_ROOM;
}

Room::~Room() {
}

Room * Room::Find(std::string name)
{
	return this;
}
