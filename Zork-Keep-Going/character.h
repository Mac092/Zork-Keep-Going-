#include <string>
#include <vector>
#include <memory.h>
#include "entity.h"
#include "weapon.h"
#include "room.h"


class Character: public Entity {

public:
	
	Character(std::string,std::string, std::string, int, int, std::vector<std::string>, bool, weapon*, Room*);
	~Character();

	virtual Character* Find(std::string name);

	void setCurrentLocation(std::string currentLocation);
	std::string getCurrentLocation();
	void setLifePoints(int lifePoints);
	int getLifePoints();
	void setAttackStrength(int attackStrength);
	int getAttackStrength();
	void setInventory(std::vector < std::string> inventory);
	std::vector<std::string> getInventory();
	void setIsAlive(bool isAlive);
	bool getIsAlive();
	void setCurrentWeapon(weapon* weapon);
	weapon* getCurrentWeapon();


private:
	std::string currentLocation;
	int lifePoints;
	int attackStrength;
	std::vector<std::string> inventory; //allocated memory
	bool isAlive;
	weapon* currentWeapon;
};
