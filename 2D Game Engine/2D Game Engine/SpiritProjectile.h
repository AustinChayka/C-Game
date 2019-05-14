#ifndef SpiritProjectile_h
#define SpiritProjectile_h

#include "Projectile.h"

class SpiritProjectile : public Projectile {

public:

	SpiritProjectile(float x, float y, float init_vX, float init_vY, int init_xDir, int init_yDir, 
		GameObject * init_spawner, GameObject * init_spawn);

	~SpiritProjectile();

	virtual void Update(LevelManager * game);

	bool OverrideCollision(GameObject * go);

	void OnCollision(GameObject * go, LevelManager * game);

private:

	GameObject * target, * spawn;

	int delay = 15, particleDelay = 0;

};

#endif