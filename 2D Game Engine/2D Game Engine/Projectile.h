#ifndef Projectile_h
#define Projectile_h

#include "GameObject.h"

class Projectile : public GameObject {

public:

	Projectile(float x, float y, float init_vX, float init_vY, int init_xDir, int init_yDir, GameObject * init_spawner);

	~Projectile();

	void Update(LevelManager * game);

	void OnCollision(GameObject * go);
	
private:

	int xDir, yDir;

	GameObject * spawner;

	int particleDelay = 10, maxDistance = 1000;

};

#endif