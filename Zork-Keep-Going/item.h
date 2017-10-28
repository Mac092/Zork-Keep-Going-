#ifndef ITEM
#define ITEM
#include "entity.h"
#include <vector>
class Item : public Entity
{
public:
	Item(std::string name, std::string description, Entity* parent );
	~Item();

	virtual Item* Find(std::string name);
	std::vector<Item*> getItems();
	void setItems(std::vector<Item*> items);
private:

	std::vector<Item*> items;
};
#endif
