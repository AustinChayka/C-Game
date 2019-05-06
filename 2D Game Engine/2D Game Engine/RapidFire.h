#ifndef RapidFire_h
#define RapidFire_h

#include "Item.h"

class RapidFire : public Item {

public:

	RapidFire();

	~RapidFire();

	void OnPickup(LevelManager * game, Player * p);
	void OnShotFired(LevelManager * game, Player * p, Projectile *& proj);

};

#endif