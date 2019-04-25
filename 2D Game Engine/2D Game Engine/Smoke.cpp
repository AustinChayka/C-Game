#include "Smoke.h"

#include <cmath>

Smoke::Smoke(float init_x, float init_y) : Particle(init_x, init_y + 2, 5, 5, 50, 50, 50, 80) {
	
   	shrink = false;
	collidable = false;
	solid = false;
	moveable = false;

	vX = (rand() % 6 - 3) / 10.0f;

	vY = -2;

}

Smoke::~Smoke() {}

void Smoke::Update(LevelManager * game) {

	Particle::Update(game);

	width += .07f;
	height += .07f;

	if(width > 30) dead = true;

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
