#include "PotMimicTentacle.h"

#include "PotMimic.h"

PotMimicTentacle::PotMimicTentacle(float x, float y) : GameObject("assets/PotMimic.png", x, y, 24, 35, 3) {

	tileY = 2;

	collidable = true;
	solid = false;
	moveable = false;

	damageable = true;
	maxHealth = health = 3;

}

PotMimicTentacle::~PotMimicTentacle() {}

void PotMimicTentacle::Update(LevelManager * game) {

	tileX += .15f;

	if(tileX > 4) {
		tileX = 0;
		if(statusFlag == 0) {
			statusFlag = 1;
			tileY = 1;
		}
	}

}

void PotMimicTentacle::OnCollision(GameObject * go, LevelManager * game) {

	if(statusFlag == 1 && dynamic_cast<PotMimicTentacle *>(go) == nullptr && dynamic_cast<PotMimic *>(go) == nullptr)
		go->DealDamage(1, game, this);

}