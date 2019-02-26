#ifndef Spirit_h
#define Spirit_h

#include "GameObject.h"

class Spirit : public GameObject {

public:

	Spirit(float x, float y);

	~Spirit();

	void Update(LevelManager * game);

	void DealDamage(int d, LevelManager * game, GameObject * go);

private :

	float deg, radius = 15, rotPerSec = 0.5f;
	int particleDelay = 4, particleTimer = particleDelay, projectileDelay = 180, projectileTimer = projectileDelay;
	GameObject * target;

	void OnDeath(LevelManager * game);

};

#endif