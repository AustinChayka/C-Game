#ifndef CursedFire_h
#define CursedFire_h

#include "GameObject.h"

class CursedFire : public GameObject {

public:

	CursedFire(float x, float y, float scale);
	~CursedFire();

	void Update(LevelManager * game);

	void OnCollision(GameObject * go, LevelManager * game);

	bool OverrideCollision(GameObject * go);

private:

	float lifeTime = -1;

};

#endif