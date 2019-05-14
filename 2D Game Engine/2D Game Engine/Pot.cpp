#include "Pot.h"

#include "Debris.h"
#include "GoldDrop.h"

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

void Pot::OnDeath(LevelManager * game, GameObject * go) {

	GameObject::OnDeath(game, go);

	game->AddObject(new Debris("assets/StageObjects/Pot.png", 16, 24, tileX, 0, 3, x, y));

	for(int i = 0; i < rand() % 4 + 2; i++) {
		GameObject * gd = new GoldDrop(GetXCenter(), GetYCenter(), 1);
		gd->SetVX(rand() % 6 - 3);
		gd->SetVY(rand() % 6);
		game->AddObject(gd);
	}

}

void Pot::Update(LevelManager * game) {
	
}

void Pot::OnCollision(GameObject * go, LevelManager * game) {
	
	if (!solid) return;

}
