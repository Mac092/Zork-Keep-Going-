
#include <vector>
#include "entity.h"
#include "player.h"
#include <time.h>
#include "..\json-develop\src\json.hpp"

class World {
public:
	World();
	~World(); 
	void initializeEntitiesData();
	Entity* find(std::string entityName, EntityType entityType);
	//void evaluatePlayersAction();
	std::vector<std::string> buildUserFullInput(std::vector<std::string> structuredPlayerInput, const std::string playerInput);
	
private:

	std::vector<Entity*> worldEntities;
	Player * player = nullptr;
	clock_t clock_timer = NULL;
	
};