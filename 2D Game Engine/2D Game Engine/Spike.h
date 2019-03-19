#ifndef Spike_h
#define Spike_h

#include "GameObject.h"

class Spike : public GameObject {

public:

	Spike(float x, float y);

	~Spike();

	void Update(LevelManager * game);
	void OnCollision(GameObject * go, LevelManager * game);

private:

	bool activated = false, triggered = false;
	int activationDelay = 20, retractionDelay = 120, delay, bleedDelay = 60;

};

#endif