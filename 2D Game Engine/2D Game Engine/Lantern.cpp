#include "Lantern.h"

#include "Spirit.h"
#include "Debris.h"

Lantern::Lantern(float x, float y) : GameObject("assets/StageObjects/Lantern.png", x, y, 9, 15, 3) {

	spawns = rand() % 2 + 1;

	damageable = true;
	health = 2;

	collidable = true;
	solid = false;
	moveable = false;

}

Lantern::~Lantern() {}

void Lantern::Update(LevelManager * game) {

	

	if(delay > 0) delay--;
	else {
		if(spawns == 0) {
			dead = true;
			OnDeath(game, nullptr);
			return;
		}
		game->AddObject(new Spirit(GetXCenter() - 13, GetYCenter() - 29));
		delay = (rand() % 4 + 3) * 30;
		spawns--;
	}

}

void Lantern::OnDeath(LevelManager * game, GameObject * go) {

	GameObject::OnDeath(game, go);

	game->AddObject(new Spirit(GetXCenter() - 13, GetYCenter() - 29));
	game->AddObject(new Debris("assets/StageObjects/Lantern.png", 15, 9, 0, 0, 3, x, y));

}
