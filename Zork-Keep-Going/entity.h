#ifndef ENTITY_C
#define ENTITY_C

#include <string>
#include <list>

enum EntityType { ENTITY_ROOM, ENTITY_EXIT, ENTITY_CHARACTER, ENTITY_PLAYER, ENTITY_ITEM, ENTITY_WEAPON, ENTITY_ENTITY };

class Entity
{
public:

	Entity(const std::string name, const std::string description, Entity* belongsTo);
	~Entity();

	std::string getName() const;
	std::string getDescription() const;
	Entity* getBelongsTo() const;
	void setBelongsTo(Entity * belongsTo);

	virtual Entity* Find(std::string name) = 0;

	EntityType type;

private:

	const std::string name = nullptr;
	const std::string description = nullptr;
	Entity * belongsTo = nullptr;
	std::list<Entity*> dependentEntities;
	
};

#endif // !ENTITY_C
