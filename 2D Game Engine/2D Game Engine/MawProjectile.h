#ifndef MawProjectile_h
#define MawProjectile_h

#include "Projectile.h"

class MawProjectile : public Projectile {

public:

	MawProjectile(float x, float y, float init_vX, float init_vY, int init_xDir, int init_yDir, GameObject * init_spawner);

	~MawProjectile();

	void Update(LevelManager * game);

	void OnCollision(GameObject * go, LevelManager * game);

private:

	int particleDelay = 5;

};

#endif