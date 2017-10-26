
#include "character.h"


Character::Character(std::string name, std::string description, std::string currentLocation, int lifePoints, int attackStrength, 
	std::vector <std::map<std::string, int>> inventory, bool isAlive, Weapon* currentWeapon, Room* room) : Entity(name, description, room)
{
	setCurrentLocation(currentLocation);
	setLifePoints(lifePoints);
	setAttackStrength(attackStrength);
	setInventory(inventory);
	setIsAlive(isAlive);
	setCurrentWeapon(currentWeapon);
	
}



Character::~Character() {
}

Character * Character::Find(std::string name)
{
	return this;
}


void Character::setCurrentLocation(std::string currentLocation)
{
	this->currentLocation = currentLocation;
}

std::string Character::getCurrentLocation()
{
	return currentLocation;
}

void Character::setLifePoints(int lifePoints)
{
	this->lifePoints = lifePoints;
}

int Character::getLifePoints()
{
	return lifePoints;
}

void Character::setAttackStrength(int attackStrength)
{
	this->attackStrength = attackStrength;
}

int Character::getAttackStrength()
{
	return attackStrength;
}

void Character::setInventory(std::vector<std::map<std::string, int>> inventory)
{
	this->inventory = inventory;
}

std::vector<std::map<std::string, int>> Character::getInventory()
{
	return inventory;
}



void Character::setIsAlive(bool isAlive)
{
	this->isAlive = isAlive;
}

bool Character::getIsAlive()
{
	return isAlive;
}

void Character::setCurrentWeapon(Weapon * weapon)
{
	currentWeapon = weapon;
}

Weapon * Character::getCurrentWeapon()
{
	return currentWeapon;
}

