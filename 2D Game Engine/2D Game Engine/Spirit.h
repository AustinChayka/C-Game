#ifndef Spirit_h
#define Spirit_h

#include "GameObject.h"

class Spirit : public GameObject {

public:

	Spirit(float x, float y);

	~Spirit();

	void Update(LevelManager * game);

private :

	float deg, targetX = 0, targetY = 0, radius = 15;
	int particleDelay = 4, particleTimer = particleDelay, projectileDelay = 180, projectileTimer = projectileDelay;

};

#endif