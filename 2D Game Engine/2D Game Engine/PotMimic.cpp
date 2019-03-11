#include "PotMimic.h"

#include "PotMimicTentacle.h"
#include "Pot.h"

PotMimic::PotMimic(float x, float y) : GameObject("assets/PotMimic.png", x, y, 24, 35, 3) {

	collidable = true;
	solid = false;
	moveable = false;

	damageable = true;
	health = 8;

}

PotMimic::~PotMimic() {}

void PotMimic::Update(LevelManager * game) {

	if(statusFlag == 0) {
		if(tileX < 4) tileX += .07f;
		if(tileX > 4) {
			tileX = 3;
			statusFlag = 1;
		}
	}

	if(statusFlag == 1) {

		if(delay > 0) delay--;
		else {
			int spawnX = (rand() % 2 == 0 ? 1 : -1) * (GetXCenter() + rand() % 300  + 100 - 36);
			for(auto go : *game->GetObjects()) if(go->IsAt(spawnX, y + 35 * 3 + 1) && go->IsSolid() && !go->IsMoveable()) {
				game->AddObject(new PotMimicTentacle(spawnX, y));
				delay = 270;
				return;
			}
		}

	}

}

void PotMimic::OnCollision(GameObject * go, LevelManager * game) {

	if(statusFlag == 1 && dynamic_cast<PotMimicTentacle *>(go) == nullptr) go->DealDamage(3, game, this);
	else if(go->IsDamagable() && dynamic_cast<Pot *>(go) == nullptr && statusFlag == -1) {
		statusFlag = 0;
		go->DealDamage(5, game, this);
	}

}

void PotMimic::DealDamage(int d, LevelManager * game, GameObject * go) {

	GameObject::DealDamage(d, game, go);

	if(statusFlag == -1) statusFlag = 0;

}
