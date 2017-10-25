#include "world.h"
#include "character.h"
#include "globals.h"
#include "json.hpp"
#include <fstream>
#include <vector>
#include <iostream>


Character* mainCharacter;
World::World() {
}

World::~World() {

	//The entities structures created shall be destroyed in the creation opposite order
}

void World::initializeEntitiesData()
{
	std::ifstream i(ENTITIES_JSON_PATH);
	nlohmann::json jCharacters;
	i >> jCharacters;
	nlohmann::json::iterator jsonEntitiesIterator;

	for (jsonEntitiesIterator = jCharacters.begin(); jsonEntitiesIterator != jCharacters.end(); jsonEntitiesIterator++) {

		if (jsonEntitiesIterator.value()["Type"] == ENTITY_KEY_ROOMS) {
			std::cout << jsonEntitiesIterator.value()["Type"] << ' \n';
			std::cout << jsonEntitiesIterator.value()["Name"] << ' \n';
			std::cout << jsonEntitiesIterator.value()["Description"] << ' \n';
			Room * room = new Room(jsonEntitiesIterator.value()["Name"], jsonEntitiesIterator.value()["Description"], nullptr);
			worldEntities.push_back(room);
		}
		else if (jsonEntitiesIterator.value()["Type"] == ENTITY_KEY_EXITS) {
			std::cout << jsonEntitiesIterator.value()["Type"];
		}
		else if (jsonEntitiesIterator.value()["Type"] == ENTITY_KEY_CHARACTERS) {
			std::cout << jsonEntitiesIterator.value()["Type"];
		}
		else if (jsonEntitiesIterator.value()["Type"] == ENTITY_KEY_PLAYERS) {
			std::cout << jsonEntitiesIterator.value()["Type"] << ' \n';
		}
		else if (jsonEntitiesIterator.value()["Type"] == ENTITY_KEY_ITEMS) {
			std::cout << jsonEntitiesIterator.value()["Type"];
		}
		else if (jsonEntitiesIterator.value()["Type"] == ENTITY_KEY_WEAPONS) {
			std::cout << jsonEntitiesIterator.value()["Type"];
		}
	}
	Room *foundRoom = (Room*)find("Outskirts", ENTITY_ROOM);
}

Entity* World::find(std::string entityName, EntityType entityType)
{
	Entity * entity = nullptr;
	for (auto it = worldEntities.begin(); it != worldEntities.end(); ++it) {
		if ((*it)->type == entityType) {
			entity = (*it)->Find(entityName);
		}
	}
	return entity;
}

//We split the user's written input in words in order to enable individual word evaluation
std::vector<std::string> World::buildUserFullInput(std::vector<std::string> structuredPlayerInput, const std::string playerInput)
{
	const char* playerInputData = playerInput.c_str();
	int wordBeginning = 0;
	int wordCounter = 0;

	for (unsigned int wordIndex = 0; wordIndex <= playerInput.length(); ++wordIndex) {
		wordCounter++;
		if (playerInputData[wordIndex] == ' ') {
			structuredPlayerInput.push_back(playerInput.substr(wordBeginning, wordCounter - 1));
			wordBeginning = wordIndex + 1;
			wordCounter = 0;
		}
	}
	structuredPlayerInput.push_back(playerInput.substr(wordBeginning, wordCounter));
	return structuredPlayerInput;
}





