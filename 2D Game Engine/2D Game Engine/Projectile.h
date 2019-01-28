#ifndef Projectile_h
#define Projectile_h

#include "GameObject.h"

class Projectile : public GameObject {

public:

	Projectile(const char * path, float x, float y, float init_vX, float init_vY, int init_xDir, int init_yDir, GameObject * init_spawner);

	~Projectile();

	void Update(LevelManager * game);

	void OnCollision(GameObject * go, LevelManager * game);
	
protected:

	int xDir, yDir;

	GameObject * spawner;

	int maxDistance = 1000;

};

#endif