#ifndef Heart_h
#define Heart_h

#include "Item.h"

class Heart : public Item {

public:

	Heart(float x, float y);

	virtual void OnPickup(LevelManager * game, Player * p);

	~Heart();

};

#endif