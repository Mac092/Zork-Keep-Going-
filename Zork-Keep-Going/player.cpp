#include "player.h"

Player::Player(const std::string name, const std::string description, Entity * owner) : Entity(name, description, owner) {

	type = ENTITY_PLAYER;
}


Player::~Player() {
}
