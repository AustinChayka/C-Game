#ifndef Ember_h
#define Ember_h

#include "Particle.h"

class Ember : public Particle {

public:

	Ember(float init_x, float init_y, float init_vX, float init_vY);

	~Ember();

	void OnCollision(GameObject * go, LevelManager * game);

	void Update(LevelManager * game);

};

#endif