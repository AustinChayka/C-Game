#ifndef VolatileHeart_h
#define VolatileHeart_h

#include "Item.h"

class VolatileHeart : public Item {

public:

	VolatileHeart();

	~VolatileHeart();
	
	void OnPickup(LevelManager * game, Player * p);
	void OnDamageTaken(LevelManager * game, GameObject * go, Player * p);
	void Update(LevelManager * game, Player * p);

private:

	int explosionDelay = 0;

};

#endif