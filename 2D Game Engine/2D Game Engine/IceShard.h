#ifndef IceShard_h
#define IceShard_h

#include "Projectile.h"

class IceShard : public Projectile {

public:

	IceShard(float x, float y, float vX, float vY, int xDir, int yDir, GameObject * spawner, float init_scale);

	~IceShard();

	virtual void Update(LevelManager * game);

	virtual void OnCollision(GameObject * go, LevelManager * game);

protected:

	bool collided = false;

};

#endif