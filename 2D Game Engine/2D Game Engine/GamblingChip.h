#ifndef GamblingChpi_h
#define GamblingChip_h

#include "Item.h"

class GamblingChip : public Item {

public:

	GamblingChip();

	~GamblingChip();

	void OnPickup(LevelManager * game, Player * p);
	void OnShotFired(LevelManager * game, Player * p, Projectile *& proj);

};

#endif