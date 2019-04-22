#include "Campfire.h"

#include "Enemy.h"
#include "RegenStatus.h"
#include "Smoke.h"

Campfire::Campfire(float x, float y) : GameObject("assets/StageObjects/Campfire.png", x, y, 41, 37, 3) {

	solid = false;
	moveable = false;

}

Campfire::~Campfire() {}

void Campfire::Update(LevelManager * game) {

	for(auto go : *game->GetObjects()) if(dynamic_cast<Enemy *>(go) != nullptr && 
		DistanceToSquared(go) <= 300 * 300) ((Enemy *)go)->AddStatus(new RegenStatus(1));

	if(delay > 0) delay--;
	else {

		game->AddObject(new Smoke(GetXCenter(), y));
		delay = 10;

	}

	tileX += .08f;
	if(tileX > 5) tileX = 0;

}
