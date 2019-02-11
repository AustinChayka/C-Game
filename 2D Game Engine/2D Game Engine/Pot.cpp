#include "Pot.h"

#include "Debris.h"

Pot::Pot(float x, float y, bool init_solid) : GameObject("assets/Pot.png", x, y, 16, 24, 3) {

	collidable = true;
	solid = init_solid;
	moveable = solid;

	damageable = true;
	health = 1;

	if (!solid) {
		tileX = 1;
		renderLayer = 0;
	}

}

Pot::~Pot() {



}

void Pot::OnDeath(LevelManager * game) {

	game->AddObject(new Debris("assets/Pot.png", 16, 24, tileX, 0, 3, x, y));

}

void Pot::Update(LevelManager * game) {

	if(!solid) return;

	vY += .7f;

}

void Pot::OnCollision(GameObject * go, LevelManager * game) {

	if (!solid) return;

	if(go->IsMoveable() && GetCollisionWall(go) != TOP) go->SetVX(go->GetVX() / 1.2f);

}
