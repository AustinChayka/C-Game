#ifndef WraithProjectile_h
#define WraithProjectile_h

#include "Projectile.h"

class WraithProjectile : public Projectile {

public:

	WraithProjectile(float x, float y, float vX, float vY, int xDir, int yDir, GameObject * spawner);
	
	void Update(LevelManager * game);

	~WraithProjectile();
	
private:

	int delay = 4;
	float amplitude;

};

#endif