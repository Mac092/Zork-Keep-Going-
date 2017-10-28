
#include "item.h"


Item::Item(std::string name, std::string description, Entity * parent)
	:Entity(name, description, parent)
{
}

Item::~Item() {
}

Item * Item::Find(std::string name)
{
	return this;
}

std::vector<Item*> Item::getItems()
{
	return items;
}

void Item::setItems(std::vector<Item*> items)
{

}


