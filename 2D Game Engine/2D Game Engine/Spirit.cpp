#include "Spirit.h"

#include "Player.h"
#include "Particle.h"
#include "CursedFireball.h"
#include "Room.h"
#include "Firestatus.h"
#include "CursedFireStatus.h"
#include "Lantern.h"
#include "Corpse.h"

Spirit::Spirit(float x, float y) : Enemy("assets/Enemies/Spirit.png", x, y, 13, 29, 2, 2) {

	collidable = true;
	moveable = false;
	solid = false;

	deg = rand() % 360;
	
}

Spirit::~Spirit() {}

void Spirit::Update(LevelManager * game) {

	Enemy::Update(game);

	tileX += 0.1f;
	if(tileX > 6) tileX = 0;

	for(auto go : *game->GetObjects()) if(go != parent && dynamic_cast<Player*>(go) != nullptr) {
		
		target = go;
				
	}

	if(target == nullptr) return;

	if(projectileTimer < 0 && y > target->GetY() && y + height < target->GetY() + target->GetHeight()) {

		float dX = target->GetX() - x, dY = target->GetY() - y;
		game->AddObject(new CursedFireball(GetXCenter(), GetYCenter(), dX / 20, dY / 20, 0, 0, parent == nullptr ? this : parent));
		projectileTimer = projectileDelay;

	} else projectileTimer--;
	
	if(parent == nullptr) {
		vX = -sin(deg * M_PI / 180) * radius + (target->GetXCenter() - x) / radius;
		vY = -cos(deg * M_PI / 180) * radius + (target->GetYCenter() - y) / radius;
	} else {
		x = parent->GetXCenter() + cos(deg) * radius * 10;
		y = parent->GetYCenter() + sin(deg) * radius * 10;
	}

	deg += (rotPerSec * 360 / 60) / (parent == nullptr ? 1 : 50);

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

void Spirit::SetTarget(GameObject * go) {

	target = go;

}

GameObject * Spirit::GetTarget() {

	return target;

}

void Spirit::SetDeg(float d) {

	deg = d;

}

void Spirit::SetParent(GameObject * go) {

	parent = go;

}

bool Spirit::OverrideStatus(Status * s) {

	return dynamic_cast<FireStatus *>(s) != nullptr || dynamic_cast<CursedFireStatus *>(s) != nullptr;

}

bool Spirit::OverrideCollision(GameObject * go) {

	return dynamic_cast<Spirit *>(go) != nullptr || dynamic_cast<Lantern *>(go) != nullptr;

}

void Spirit::OnDeath(LevelManager * game, GameObject * go) {

	Enemy::OnDeath(game, go);

	game->AddObject(new Corpse("assets/Enemies/Spirit.png", x, y, 13, 29, 0, 1, 2));

}
