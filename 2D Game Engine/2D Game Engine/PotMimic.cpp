#include "PotMimic.h"

#include "PotMimicTentacle.h"
#include "Pot.h"
#include "ImageTile.h"

PotMimic::PotMimic(float x, float y) : Enemy("assets/Enemies/PotMimic.png", x, y, 24, 35, 3, 8) {

	collidable = true;
	solid = false;
	moveable = false;
	
}

PotMimic::~PotMimic() {}

void PotMimic::Update(LevelManager * game) {

	Enemy::Update(game);

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
			int spawnX = NULL, spawnY = NULL;
			if(target == nullptr || DistanceToSquared(target) > 500 * 500) {
				for(auto go : *game->GetObjects()) if(go->IsDamagable() && DistanceToSquared(go) <= 500 * 500 &&
					dynamic_cast<PotMimicTentacle *>(go) == nullptr && dynamic_cast<PotMimic *>(go) == nullptr) {
					spawnX = go->GetXCenter();
					spawnY = go->GetY() + go->GetHeight() - height;
				}
			} else {
				spawnX = target->GetXCenter();
				spawnY = target->GetY() + target->GetHeight() - height;
			}
			for(auto go : *game->GetObjects()) if(go->IsAt(spawnX + 12 * 3, spawnY + 35 * 3 + 1) && go->IsSolid() && !go->IsMoveable()) {
				if(spawnX != NULL && spawnY != NULL) game->AddObject(new PotMimicTentacle(spawnX - 12 * 3, spawnY));
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

	Enemy::DealDamage(d, game, go);

	if(statusFlag == -1) statusFlag = 0;
	
}

void PotMimic::OnDeath(LevelManager * game, GameObject * go) {

	Enemy::OnDeath(game, go);

	ImageTile * tile = new ImageTile("assets/Enemies/PotMimic.png", x, y, 24, 35, 4, 0, 3, renderLayer);
	SDL_SetTextureColorMod(tile->GetTexture(), 200, 200, 200);
	game->AddTile(tile);

}
