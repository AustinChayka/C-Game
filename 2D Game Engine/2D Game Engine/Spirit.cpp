#include "Spirit.h"

#include "Player.h"
#include "Particle.h"
#include "CursedFireball.h"

Spirit::Spirit(float x, float y) : GameObject("assets/Spirit.png", x, y, 35, 51) {

	collidable = true;
	moveable = false;
	solid = false;

	targetX = x;
	targetY = y;

	deg = rand() % 360;

	damageable = true;
	health = 4;

}

Spirit::~Spirit() {}

void Spirit::Update(LevelManager * game) {

	for(auto go : game->GetObjects()) if(dynamic_cast<Player*>(go) != nullptr && DistanceToSquared(go) < 100000) {

		targetX = go->GetX();
		targetY = go->GetY();

		if (projectileTimer < 0) {

			float dX = go->GetX() - x, dY = go->GetY() - y;
			game->AddObject(new CursedFireball(GetXCenter(), GetYCenter(), dX / 20, dY / 20, 0, 0, this));
			projectileTimer = projectileDelay;

		} else projectileTimer--;

	}

	vX = sin(deg) * radius + (targetX - x) / radius;
	vY = cos(deg) * radius + (targetY - y) / radius;

	deg += .05f;

	if(deg > 360) deg = 0;

	if(particleTimer < 0) {

		game->AddObject(new Particle(GetXCenter() - 3, GetYCenter() - 3, 6, 6, 99, 206, 194, 184));
		particleTimer = particleDelay;

	} else particleTimer--;
		
}