#include "NailObject.h"

#include "Player.h"
#include "Hammer.h"

NailObject::NailObject(float x, float y, float init_vX, float init_vY) :
	GameObject("assets/Items/PossesedNail.png", x, y, 24, 24) {

	collidable = true;
	solid = false;
	moveable = true;

	grav = .6f;
	decceleration = 1.4f;

	vX = init_vX;
	vY = init_vY;

}

NailObject::~NailObject() {}

void NailObject::Update(LevelManager * game) {

	if(delay > 0) delay--;
	else if(delay == 0) {
		game->AddObject(new Hammer(GetXCenter() - 20 * 2, GetYCenter() - 50 * 4 - Game::height));
		delay--;
	}

}

bool NailObject::OverrideCollision(GameObject * go) {

	return dynamic_cast<Player *>(go) != nullptr || (grounded && go->IsDamagable());

}

void NailObject::OnCollision(GameObject * go, LevelManager * game) {

	if((!go->IsSolid() && !go->IsDamagable()) || dynamic_cast<Player *>(go) != nullptr) return;
	
	if(dynamic_cast<Hammer *>(go) != nullptr) dead = true;
	
	vX = 0;

}
