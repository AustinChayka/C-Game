#include "PotMimicTentacle.h"

#include "PotMimic.h"

PotMimicTentacle::PotMimicTentacle(float x, float y) : Enemy("assets/PotMimic.png", x, y, 24, 35, 3, 3) {

	tileY = 2;

	collidable = true;
	solid = false;
	moveable = false;
	
}

PotMimicTentacle::~PotMimicTentacle() {}

void PotMimicTentacle::Update(LevelManager * game) {

	Enemy::Update(game);

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