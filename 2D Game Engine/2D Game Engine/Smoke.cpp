#include "Smoke.h"

#include <cmath>

Smoke::Smoke(float init_x, float init_y) : Particle(init_x, init_y + 2, 2, 2, 20, 20, 20, 80) {
	
   	shrink = false;
	collidable = false;

	vX = (rand() % 6 - 3) / 10.0f;

}

Smoke::~Smoke() {}

void Smoke::Update(LevelManager * game) {

	Particle::Update(game);

	vY = -2;

	width += .07f;
	height += .07f;

	if(red < 255) {
		red += 7;
		green += 7;
		blue += 7;
	} else if(red > 255) {
		red = 255;
		green = 255;
		blue = 255;
	}

	vX += (rand() % 6 - 3) / 20.0f;

}
