#ifndef Spirit_h
#define Spirit_h

#include "GameObject.h"

class Spirit : public GameObject {

public:

	Spirit(float x, float y);

	~Spirit();

	void Update(LevelManager * game);

	LevelManager * lm;

private :

	float deg, radius = 15;
	int particleDelay = 4, particleTimer = particleDelay, projectileDelay = 180, projectileTimer = projectileDelay;
	GameObject * target;

};

#endif