#include "Maw.h"

#include "Player.h"
#include "MawProjectile.h"

Maw::Maw(float x, float y) : Boss("assets/Enemies/FormlessMaw.png", x, y, 100, 100, 3, 50, "Formless Maw") {

	solid = true;
	moveable = false;

	renderLayer = 3;

	itemName = "BabyMaw";

}

Maw::~Maw() {}

void Maw::Update(LevelManager * game) {

	Enemy::Update(game);

	if(target == nullptr) for(auto go : *game->GetObjects()) if(dynamic_cast<Player *>(go) != nullptr) {
		target = go;
		break;
	} else if(!target) target == nullptr;

	if(target == nullptr) return;

	if(DistanceToSquared(target) > 100 * 100) {
		vX = (target->GetXCenter() - GetXCenter()) / 100;
	} else vX = 0;
	if(abs(GetYCenter() - target->GetYCenter()) > 3) vY = (target->GetYCenter() - GetYCenter()) / 100;

	if(delay > 0) delay--;
	else {
		if(subdelay > 0) subdelay--;
		else if(shots != 0) {
			game->AddObject(new MawProjectile(GetXCenter(), GetYCenter(), (target->GetXCenter() - GetXCenter()) / 30,
				(target->GetYCenter() - GetYCenter()) / 30, 0, 0, this));
			subdelay = 20;
			shots--;
		} else {
			delay = 120;
			shots = 3;
		}
	}

}

void Maw::OnCollision(GameObject * go, LevelManager * game) {

	go->DealDamage(3, game, this);

}

bool Maw::OverrideCollision(GameObject * go) {

	return dynamic_cast<Player *>(go) == nullptr;

}
