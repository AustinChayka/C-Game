#ifndef Projectile_h
#define Projectile_h

#include "GameObject.h"

class Projectile : public GameObject {

public:

	Projectile(const char * path, float x, float y, float init_vX, float init_vY, int init_xDir, int init_yDir, GameObject * init_spawner);

	~Projectile();

	void Update(LevelManager * game);

	void OnCollision(GameObject * go, LevelManager * game);

	bool OverrideCollision(GameObject * go);

	float DistanceTraveled();

	float GetSpawnX();
	float GetSpawnY();
	float GetSpawnVX();
	float GetSpawnVY();

	int GetLifeTime();

	void SetSpawner(GameObject * go);
	
protected:

	int xDir, yDir, lifeTime = 0;

	float distance = 0, spawnX, spawnY, spawnVX, spawnVY;

	GameObject * spawner;

	int maxDistance = 1000, damage = 1;

};

#endif