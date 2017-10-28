#ifndef EXIT
#define EXIT

#include <string>
#include "entity.h"
#include "room.h"
#include "item.h"
class Exit : public Entity
{
public:
	
	Exit(std::string name, std::string description, Room * origin, std::string orientation, std::string destination, bool locked, Item * item);
	~Exit();

	virtual Exit* Find(std::string name);
};
#endif
