#ifndef DoubleVision_h
#define DoubleVision_h

#include "Item.h"

class DoubleVision : public Item {

public:

	DoubleVision();

	~DoubleVision();

	void OnShotFired(LevelManager * game, Player * p, Projectile *& proj);

};

#endif