#ifndef Smoke_h
#define Smoke_h

#include "Particle.h"

class Smoke : public Particle {

public:

	Smoke(float init_x, float init_y);

	~Smoke();

	void Update(LevelManager * game);

};

#endif