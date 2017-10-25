#include "entity.h"


Entity::Entity(const std::string name, const std::string description, Entity * belongs) : 
	name(name), description(description), belongsTo(belongs) {
	
	type = ENTITY_ENTITY;
}

Entity::~Entity() {
}

std::string Entity::getName() const {
	return std::string();
}

std::string Entity::getDescription() const {
	return std::string();
}

Entity * Entity::getBelongsTo() const {
	return belongsTo;
}

void Entity::setBelongsTo(Entity * belongs)
{
	belongsTo = belongs;
}



void Entity::Look() const
{
}

