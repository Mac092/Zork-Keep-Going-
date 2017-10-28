#ifndef CHARACTER
#define CHARACTER

#include <string>
#include <vector>
#include <map>
#include <memory.h>
#include "entity.h"
#include "weapon.h"
#include "room.h"


class Character: public Entity {

public:
	
	Character(std::string,std::string, int, int, std::map<std::string, int>, bool, Weapon*, Room*);
	~Character();

	virtual Character* Find(std::string name);

	//Character's class variables getters and setters
	void setCurrentLocation(std::string currentLocation);
	std::string getCurrentLocation();
	void setLifePoints(int lifePoints);
	int getLifePoints();
	void setAttackStrength(int attackStrength);
	int getAttackStrength();
	void setInventory(std::map<std::string, int> inventory);
	std::map<std::string, int> getInventory();
	void setIsAlive(bool isAlive);
	bool getIsAlive();
	void setCurrentWeapon(Weapon* weapon);
	Weapon* getCurrentWeapon();


private:
	std::string currentLocation;
	int lifePoints;
	int attackStrength;
	std::map<std::string, int> inventory; //allocated memory
	bool isAlive;
	Weapon* currentWeapon;
};
#endif