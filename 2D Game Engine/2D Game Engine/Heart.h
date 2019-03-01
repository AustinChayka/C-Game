#ifndef Heart_h
#define Heart_h

#include "Item.h"

class Heart : public Item {

public:

	Heart();

	virtual void OnPickup(LevelManager * game, Player * p);
	virtual void OnDamageTaken(LevelManager * game, GameObject * go, Player * p);

	~Heart();

};

#endif