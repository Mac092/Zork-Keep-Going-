#include "world.h"
#include "character.h"
#include "globals.h"
#include "exit.h"
#include "json.hpp"
#include <fstream>
#include <vector>
#include <iostream>


World::World() {
}

World::~World() {

	//The entities structures created shall be destroyed in the creation opposite order
	if (!worldEntities.empty()) {
		for (std::vector<Entity*>::iterator it = worldEntities.end(); it != worldEntities.begin(); it--) {
			delete *it;
		}
	}
	
}

void World::welcomeToZork()
{
	std::printf("Welcome to Zork - Keep Going! This is a conversation game where you will get under the skin of a Intelligence "
	"Agency member, who among other qualified companions will try to obtain the antidote for the upcoming world spread disease. "
	"Mankind's future will be settled depending on the result of this mission." "\n");
}

void World::initializeEntitiesData()
{
	std::ifstream i(ENTITIES_JSON_PATH);
	nlohmann::json jCharacters;
	i >> jCharacters;

	jCharacters = sortJSONEntities(jCharacters);
	nlohmann::json::iterator sortedEntitiesIterator;

	for (sortedEntitiesIterator = jCharacters.begin(); sortedEntitiesIterator != jCharacters.end(); sortedEntitiesIterator++) {

		if (sortedEntitiesIterator.value()["Type"] == ENTITY_KEY_ROOMS) {
			Room *room = new Room(sortedEntitiesIterator.value()["Name"], sortedEntitiesIterator.value()["Description"], nullptr);
			worldEntities.push_back(room);
		}
		else if (sortedEntitiesIterator.value()["Type"] == ENTITY_KEY_EXITS) {
			Item *exitKey = nullptr;
			Room *exitRoom = (Room*)find(sortedEntitiesIterator.value()["Origin"], ENTITY_ROOM);
			if (!sortedEntitiesIterator.value()["Key"].is_null()) {
				exitKey = (Item*)find(sortedEntitiesIterator.value()["Key"], ENTITY_ITEM);
			}

			Exit * exit = new Exit(sortedEntitiesIterator.value()["Name"], sortedEntitiesIterator.value()["Description"], exitRoom,
				sortedEntitiesIterator.value()["Orientation"],sortedEntitiesIterator.value()["Destination"],
				sortedEntitiesIterator.value()["Locked"], exitKey);
			worldEntities.push_back(exit);
		}
		else if (sortedEntitiesIterator.value()["Type"] == ENTITY_KEY_CHARACTERS) {
			Room *characterRoom = (Room*)find(sortedEntitiesIterator.value()["CurrentLocation"], ENTITY_ROOM);
			Weapon *characterWeapon = (Weapon*)find(sortedEntitiesIterator.value()["CurrentWeapon"], ENTITY_WEAPON);
			
			Character *character = new Character(sortedEntitiesIterator.value()["Name"], sortedEntitiesIterator.value()["Description"],
				sortedEntitiesIterator.value()["HP"],sortedEntitiesIterator.value()["Attack"],
				sortedEntitiesIterator.value()["Inventory"],sortedEntitiesIterator.value()["IsAlive"],
				characterWeapon,characterRoom);
			worldEntities.push_back(character);
		}
		else if (sortedEntitiesIterator.value()["Type"] == ENTITY_KEY_PLAYERS) {
			Room *playerRoom = (Room*)find(sortedEntitiesIterator.value()["CurrentLocation"], ENTITY_ROOM);
			Weapon *playerWeapon = nullptr;
			if (!sortedEntitiesIterator.value()["Key"].is_null()) {
				playerWeapon = (Weapon*)find(sortedEntitiesIterator.value()["CurrentWeapon"], ENTITY_WEAPON);
			}

			Player *player = new Player(sortedEntitiesIterator.value()["Name"], sortedEntitiesIterator.value()["Description"],
				sortedEntitiesIterator.value()["HP"], sortedEntitiesIterator.value()["Attack"],
				sortedEntitiesIterator.value()["Inventory"], sortedEntitiesIterator.value()["IsAlive"],
				playerWeapon, playerRoom);
			worldEntities.push_back(player);
		}
		else if (sortedEntitiesIterator.value()["Type"] == ENTITY_KEY_ITEMS) {
			Item *item = nullptr;

			if (!sortedEntitiesIterator.value()["CurrentLocation"].is_null()) {
				Room *itemRoom = nullptr;
				itemRoom = (Room*)find(sortedEntitiesIterator.value()["CurrentLocation"], ENTITY_ROOM);
				if (!itemRoom) {
					delete(itemRoom);
					Item *itemParent = nullptr;
					itemParent = (Item*)find(sortedEntitiesIterator.value()["CurrentLocation"], ENTITY_ITEM);
				}
				item = new Item(sortedEntitiesIterator.value()["Name"], sortedEntitiesIterator.value()["Description"],
					nullptr);
			}
			else {
				item = new Item(sortedEntitiesIterator.value()["Name"], sortedEntitiesIterator.value()["Description"],
				nullptr);
			}
			
			item->setItems(sortedEntitiesIterator.value()["Items"]);
			worldEntities.push_back(item);
		}
		else if (sortedEntitiesIterator.value()["Type"] == ENTITY_KEY_WEAPONS) {
			Item *itemParent = nullptr;
			if (!sortedEntitiesIterator.value()["CurrentLocation"].is_null()) {
				itemParent = (Item*)find(sortedEntitiesIterator.value()["CurrentLocation"], ENTITY_ROOM);
			}
			Item *item = new Item(sortedEntitiesIterator.value()["Name"], sortedEntitiesIterator.value()["Description"],
				itemParent);
			item->setItems(sortedEntitiesIterator.value()["Items"]);
			worldEntities.push_back(item);
		}
	}
	
}

//After getting back the unsorted Json Entities from the proper json files, this method will sort the entities in order to prepare the CORRECT creation of the c++ entities structures
nlohmann::json World::sortJSONEntities(nlohmann::json nonSortedEntities)
{
	std::vector<nlohmann::json> sortedJsonEntities;
	nlohmann::json::iterator jsonEntitiesIterator;


	for (jsonEntitiesIterator = nonSortedEntities.begin(); jsonEntitiesIterator != nonSortedEntities.end(); jsonEntitiesIterator++) {
		bool individualSorted = false;
		if (sortedJsonEntities.size() == 0) {
			sortedJsonEntities.push_back(jsonEntitiesIterator.value());
		}
		else {
			for (auto it = sortedJsonEntities.begin(); individualSorted == false && it != sortedJsonEntities.end();) {
				if (jsonEntitiesIterator.value()["Order"] <= (*it)["Order"]) {
					sortedJsonEntities.insert(it, jsonEntitiesIterator.value());
					individualSorted = true;
				}
				else if (std::next(it,1) == sortedJsonEntities.end()) {
					sortedJsonEntities.push_back(jsonEntitiesIterator.value());
					individualSorted = true;
				}
				else {
					it++;
				}
			}
		}
	}
	
	return sortedJsonEntities;
}

Entity* World::find(std::string entityName, EntityType entityType)
{
	Entity *entity = nullptr;
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
	const char *playerInputData = playerInput.c_str();
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





