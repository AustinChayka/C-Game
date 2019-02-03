#include "Spirit.h"

#include "Player.h"
#include "Particle.h"
#include "CursedFireball.h"

Spirit::Spirit(float x, float y) : GameObject("assets/Spirit.png", x, y, 35, 51) {

	collidable = true;
	moveable = false;
	solid = false;

	deg = rand() % 360;

	damageable = true;
	health = 1;

}

Spirit::~Spirit() {}

void Spirit::Update(LevelManager * game) {

	lm = game;

	for(auto go : game->GetObjects()) if(dynamic_cast<Player*>(go) != nullptr && HasLineOfSight(go, game)) {

		target = go;
				
	}

	if(target == nullptr) return;

	if(projectileTimer < 0 && HasLineOfSight(target, game)) {

		float dX = target->GetX() - x, dY = target->GetY() - y;
		game->AddObject(new CursedFireball(GetXCenter(), GetYCenter(), dX / 20, dY / 20, 0, 0, this));
		projectileTimer = projectileDelay;

	} else projectileTimer--;
	
	vX = sin(deg) * radius + (target->GetXCenter() - x) / radius;
	vY = cos(deg) * radius + (target->GetYCenter() - y) / radius;

	deg += .05f;

	if(deg > 360) deg = 0;

	if(particleTimer < 0) {

		game->AddObject(new Particle(GetXCenter() - 3, GetYCenter() - 3, 6, 6, 99, 206, 194, 184));
		particleTimer = particleDelay;

	} else particleTimer--;

	std::cout << HasLineOfSight(target, game) << std::endl;
		
}
