#ifndef CharredSkull_h
#define CharredCkull_h

#include "Item.h"

class CharredSkull : public Item {

public:

	CharredSkull();

	~CharredSkull();

	void OnShotFired(LevelManager * game, Player * p, Projectile *& proj);

};

#endif