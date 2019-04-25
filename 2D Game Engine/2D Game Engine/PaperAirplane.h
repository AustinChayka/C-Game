#ifndef PaperAirplane_h
#define PaperAirplane_h

#include "Item.h"

class PaperAirplane : public Item {

public:

	PaperAirplane();

	~PaperAirplane();

	void OnShotFired(LevelManager * game, Player * p, Projectile *& proj);
	void UpdateProjectile(LevelManager * game, Player * p, Projectile * proj);

};

#endif