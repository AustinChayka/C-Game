#ifndef IceShard_h
#define IceShard_h

#include "Projectile.h"

class IceShard : public Projectile {

public:

	IceShard(float x, float y, float vX, float vY, int xDir, int yDir, GameObject * spawner, float init_scale);

	~IceShard();

	void Update(LevelManager * game);

	void OnCollision(GameObject * go, LevelManager * game);

private:

	bool collided = false;

};

#endif