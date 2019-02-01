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
	int particleDelay = 4, delay = particleDelay;

};

#endif