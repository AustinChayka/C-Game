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

	renderLayer = 3;
	
}

Spirit::~Spirit() {}

void Spirit::Update(LevelManager * game) {

	Enemy::Update(game);

	tileX += 0.1f;
	if(tileX > 6) tileX = 0;

	if(target == nullptr) for(auto go : *game->GetObjects()) if(go != parent && dynamic_cast<Player*>(go) != nullptr) {
		target = go;
		break;
	} else if(!target || target->IsDead()) target = nullptr;

	if(target == nullptr) return;

	if(projectileTimer < 0 && y > target->GetY() && y + height < target->GetY() + target->GetHeight()) {

		float dX = target->GetX() - x, dY = target->GetY() - y;
		game->AddObject(new CursedFireball(GetXCenter(), GetYCenter(), 10 * dX / abs(dX + dY), 10 * dY / abs(dX + dY), 
			0, 0, parent == nullptr ? this : parent));
		projectileTimer = projectileDelay;

	} else projectileTimer--;
	
	if(parent == nullptr) {
		vX = -sin(deg * M_PI / 180) * radius + (target->GetXCenter() - x) / radius;
		vY = -cos(deg * M_PI / 180) * radius + (target->GetYCenter() - y) / radius;
	} else {
		if(!parent || parent->IsDead()) {
			parent == nullptr;
			return;
		}
		vX = -sin(deg * M_PI / 180) * radius + (parent->GetXCenter() - x) / radius;
		vY = -cos(deg * M_PI / 180) * radius + (parent->GetYCenter() - y) / radius;
	}

	deg += (rotPerSec * 360 / 60);

	if(deg > 360) deg = 0;

	if(particleTimer < 0) {

		game->AddObject(new Particle(GetXCenter() - 3, GetYCenter() - 3, 6, 6, 99, 206, 194, 184));
		particleTimer = particleDelay;

	} else particleTimer--;
	
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

void Spirit::SetProjectileDelay(int d) {

	projectileDelay = d;

}

bool Spirit::OverrideStatus(Status * s) {

	return dynamic_cast<FireStatus *>(s) != nullptr || dynamic_cast<CursedFireStatus *>(s) != nullptr;

}

bool Spirit::OverrideCollision(GameObject * go) {
 
	if(dynamic_cast<Projectile *>(go) != nullptr && 
		((Projectile *)go)->GetSpawner() == parent) return true;
	
	return dynamic_cast<Spirit *>(go) != nullptr || dynamic_cast<Lantern *>(go) != nullptr
		|| go == parent;

}

void Spirit::OnDeath(LevelManager * game, GameObject * go) {

	Enemy::OnDeath(game, go);

	game->AddObject(new Corpse("assets/Enemies/Spirit.png", x, y, 13, 29, 0, 1, 2));

}
