#ifndef SpiritProjectile2_h
#define SpiritProjectile2_h

#include "SpiritProjectile.h"

class SpiritProjectile2 : public SpiritProjectile {

public:

	SpiritProjectile2(float x, float y, float init_vX, float init_vY, int init_xDir, int init_yDir,
		GameObject * init_spawner, GameObject * init_spawn);

	~SpiritProjectile2();

	void Update(LevelManager * game);

};

#endif