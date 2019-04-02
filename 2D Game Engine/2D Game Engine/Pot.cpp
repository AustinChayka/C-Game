#include "Pot.h"

#include "Debris.h"

Pot::Pot(float x, float y, bool init_solid) : GameObject("assets/StageObjects/Pot.png", x, y, 16, 24, 3) {

	collidable = true;
	solid = init_solid;
	moveable = solid;

	damageable = true;
	health = 1;
	
	if (!solid) {
		tileX = 1;
		renderLayer = 0;
	} else grav = .7f;

}

Pot::~Pot() {



}

void Pot::OnDeath(LevelManager * game) {

	game->AddObject(new Debris("assets/StageObjects/Pot.png", 16, 24, tileX, 0, 3, x, y));

}

void Pot::Update(LevelManager * game) {
	
}

void Pot::OnCollision(GameObject * go, LevelManager * game) {
	
	if (!solid) return;

}
