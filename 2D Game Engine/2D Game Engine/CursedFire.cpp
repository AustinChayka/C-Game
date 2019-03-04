#include "CursedFire.h"

#include "Player.h"

CursedFire::CursedFire(float x, float y, float scale, GameObject * init_spawner) : GameObject("assets/CursedFire.png", x, y, 10, 10, scale) {

	collidable = true;
	moveable = true;
	solid = false;

	tileX = rand() % 4;

	renderLayer = 2;

	grav = .1f;

	spawner = init_spawner;

	if(dynamic_cast<Player *>(spawner) != nullptr) SDL_SetTextureAlphaMod(texture, 180);

}

CursedFire::~CursedFire() {



}

void CursedFire::Update(LevelManager * game) {

	if (lifeTime == 0) dead = true;
	else if (lifeTime != -1) lifeTime -= 1;
	
	tileX += .1f;
	if (tileX > 4) tileX = 0;

}

void CursedFire::OnCollision(GameObject * go, LevelManager * game) {

	if(lifeTime == -1) lifeTime = 145;

	if(go != spawner && go->IsSolid()) go->DealDamage(2, game, spawner);
	
}

bool CursedFire::OverrideCollision(GameObject * go) {

	return go->IsDamagable() || dynamic_cast<Player *>(go) != nullptr;

}
