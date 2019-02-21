#include "Spirit.h"

#include "Player.h"
#include "Particle.h"
#include "CursedFireball.h"
#include "Debris.h"
#include "Room.h"

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

	for(auto go : *game->GetObjects()) if(dynamic_cast<Player*>(go) != nullptr && DistanceToSquared(go) < 40000) {
		
		target = go;
				
	}

	if(target == nullptr) return;

	if(projectileTimer < 0 && y > target->GetY() && y + height < target->GetY() + target->GetHeight()) {

		float dX = target->GetX() - x, dY = target->GetY() - y;
		game->AddObject(new CursedFireball(GetXCenter(), GetYCenter(), dX / 20, dY / 20, 0, 0, this));
		projectileTimer = projectileDelay;

	} else projectileTimer--;
	
	vX = -sin(deg * M_PI / 180) * radius + (target->GetXCenter() - x) / radius;
	vY = -cos(deg * M_PI / 180) * radius + (target->GetYCenter() - y) / radius;

	deg += rotPerSec * 360 / 60;

	if(deg > 360) deg = 0;

	if(particleTimer < 0) {

		game->AddObject(new Particle(GetXCenter() - 3, GetYCenter() - 3, 6, 6, 99, 206, 194, 184));
		particleTimer = particleDelay;

	} else particleTimer--;

	visible = false;
	for(auto r : *game->GetRooms()) if(r->GetX() + r->GetWidth() - 60 > x
		&& r->GetX() + 60 < x + width
		&& r->GetY() + r->GetHeight() - 60 > y
		&& r->GetY() + 60 < y + height) visible = true;

}

void Spirit::OnDeath(LevelManager * game) {

	game->AddObject(new Debris("assets/Spirit.png", 35, 51, tileX, tileY, 1, x, y));

}
