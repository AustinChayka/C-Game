#ifndef CursedFireball_h
#define CursedFireball_h

#include "Projectile.h"

class CursedFireball : public Projectile {

public:

	CursedFireball(float x, float y, float init_vX, float init_vY, int init_xDir, int init_yDir, GameObject * init_spawner);

	~CursedFireball();

	void Update(LevelManager * game);
	void OnCollision(GameObject * go, LevelManager * game);
	
private:

	int particleDelay = 1, particleTimer = particleDelay;

};

#endif