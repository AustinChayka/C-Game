#ifndef Soul_h
#define Soul_h

#include "Item.h"

class Soul : public Item {

public:

	Soul();

	~Soul();

	void OnPickup(LevelManager * game, Player * p);

};

#endif