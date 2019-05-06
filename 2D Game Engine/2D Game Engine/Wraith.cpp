#include "Wraith.h"

#include "Player.h"
#include "Particle.h"
#include "FireStatus.h"
#include "CursedFireStatus.h"
#include "Urn.h"
#include "Corpse.h"

Wraith::Wraith(float x, float y) : Enemy("assets/Enemies/Wraith.png", x, y, 19, 22, 2, 2) {
	
	collidable = true;
	solid = false;
	moveable = false;

	renderLayer = 3;

}

Wraith::~Wraith() {}

void Wraith::Update(LevelManager * game) {

	Enemy::Update(game);
	
	tileX += 0.1f;
	if(tileX > 4) tileX = 0;

	if(target == nullptr) for(auto go : *game->GetObjects()) if(dynamic_cast<Player *>(go)) {
		target = go;
		break;
	} else if(!target || target->IsDead()) target = nullptr;

	if(target == nullptr) return;

	vX += speed * (target->GetX() - x);
	vY += speed * (target->GetY() - y);
	
	if(vX > maxSpeed) vX = maxSpeed;
	if(vY > maxSpeed) vY = maxSpeed;
	if(vX < -maxSpeed) vX = -maxSpeed;
	if(vY < -maxSpeed) vY = -maxSpeed;

	if(delay == 0) {
		Particle * p = new Particle("assets/Enemies/Wraith.png", x, y, 19, 22, tileX, tileY, 2);
		p->SetFadeSpeed(7);
		game->AddObject(p);
		delay = 4;
	} else delay--;

	if(vX < 0) tileY = 0;
	else tileY = 1;

}

void Wraith::OnCollision(GameObject * go, LevelManager * game) {

	if(!go->IsDamagable() || dynamic_cast<Urn *>(go) != nullptr || dynamic_cast<Wraith *>(go) != nullptr) return;

	go->DealDamage(1, game, this);
	
}

bool Wraith::OverrideStatus(Status * s) {

	return dynamic_cast<FireStatus *>(s) != nullptr || dynamic_cast<CursedFireStatus *>(s) != nullptr;

}

bool Wraith::OverrideCollision(GameObject * go) {

	return dynamic_cast<Wraith *>(go) != nullptr;

}

void Wraith::OnDeath(LevelManager * game, GameObject * go) {

	Enemy::OnDeath(game, go);

	game->AddObject(new Corpse("assets/Enemies/Wraith.png", x, y, 19, 22, 4, tileY, scale));

}
