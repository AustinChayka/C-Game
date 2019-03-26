#ifndef Spirit_h
#define Spirit_h

#include "Enemy.h"

class Spirit : public Enemy {

public:

	Spirit(float x, float y);

	~Spirit();

	void Update(LevelManager * game);

	void SetTarget(GameObject * go);
	GameObject * GetTarget();
	void SetDeg(float d);
	void SetParent(GameObject * go);

	bool OverrideStatus(Status * s);

private :

	float deg, radius = 15, rotPerSec = 0.5f;
	int particleDelay = 4, particleTimer = particleDelay, projectileDelay = 180, projectileTimer = projectileDelay;
	GameObject * parent = nullptr;

	void OnDeath(LevelManager * game);

};

#endif