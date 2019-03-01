#ifndef CursedFire_h
#define CursedFire_h

#include "GameObject.h"

class CursedFire : public GameObject {

public:

	CursedFire(float x, float y, float scale, GameObject * init_spawner);
	~CursedFire();

	void Update(LevelManager * game);

	void OnCollision(GameObject * go, LevelManager * game);

	bool OverrideCollision(GameObject * go);

private:

	float lifeTime = -1;

	GameObject * spawner;

};

#endif