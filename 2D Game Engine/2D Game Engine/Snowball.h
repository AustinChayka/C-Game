#ifndef Snowball_h
#define Snowball_h

#include "Projectile.h"

class Snowball : public Projectile {

public:

	Snowball(float x, float y, float vX, float vY, int xDir, int yDir, GameObject * spawner);

	~Snowball();

	void OnCollision(GameObject * go, LevelManager * game);

};

#endif