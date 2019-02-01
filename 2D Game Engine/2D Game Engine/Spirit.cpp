#include "Spirit.h"

#include "Player.h"
#include "Particle.h"

Spirit::Spirit(float x, float y) : GameObject("assets/Spirit.png", x, y, 35, 51) {

	collidable = false;
	moveable = false;

}

Spirit::~Spirit() {}

void Spirit::Update(LevelManager * game) {

	for(auto go : game->GetObjects()) if(dynamic_cast<Player*>(go) != nullptr) {

		targetX = go->GetX();
		targetY = go->GetY();

	}

	vX = cos(deg) * radius + (targetX - x) / radius;
	vY = sin(deg) * radius + (targetY - y) / radius;

	deg += .05f;

	if(deg > 360) deg = 0;

	if(delay < 0) {

		game->AddObject(new Particle(GetXCenter() - 3, GetYCenter() - 3, 6, 6, 99, 206, 194, 184));
		delay = particleDelay;

	} else delay--;
		
}