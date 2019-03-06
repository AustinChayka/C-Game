#ifndef SpiralShell_h
#define SpiralShell_h

#include "Item.h"

class SpiralShell : public Item {

public:

	SpiralShell();

	~SpiralShell();

	void UpdateProjectile(LevelManager * game, Player * p, Projectile * proj);

private:

	float radius = 25;
	
};

#endif