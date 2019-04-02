#include "Urn.h"

#include "Wraith.h"
#include "Debris.h"

Urn::Urn(float x, float y) : GameObject("assets/StageObjects/Urn.png", x, y, 15, 20, 3) {

	spawns = rand() % 2 + 1;

	damageable = true;
	health = 2;

	collidable = true;
	solid = false; 
	moveable = false;

}

Urn::~Urn() {}

void Urn::Update(LevelManager * game) {
	
	if(delay > 0) delay--;
	else {
		if(spawns == 0) {
			dead = true;
			OnDeath(game, nullptr);
			return;
		}
		game->AddObject(new Wraith(GetXCenter() - 19, GetYCenter() - 22));
		delay = (rand() % 4 + 3) * 30;
		spawns--;
	}

}

void Urn::OnDeath(LevelManager * game, GameObject * go) {

	GameObject::OnDeath(game, go);

	game->AddObject(new Wraith(GetXCenter() - 19, GetYCenter() - 22));
	game->AddObject(new Debris("assets/StageObjects/Urn.png", 15, 20, 0, 0, 3, x, y));

}
