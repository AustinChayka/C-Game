#include "Fire.h"

#include "Player.h"
#include "FireStatus.h"

Fire::Fire(float init_x, float init_y, float scale, GameObject * init_spawner) : GameObject("assets/Fire.png", init_x, init_y, 10, 10, scale) {

	collidable = true;
	moveable = true;
	solid = false;
	
	tileX = rand() % 4;

	spawner = init_spawner;

	renderLayer = 2;

	grav = .1f;

	if(dynamic_cast<Player *>(spawner) != nullptr) SDL_SetTextureAlphaMod(texture, 180);

}

Fire::~Fire() {}

void Fire::Update(LevelManager * game) {

	if(burnDelay > 0) burnDelay--;

	if(lifeTime == 0) dead = true;
	else if(lifeTime != -1) lifeTime -= 1;

	tileX += .1f;
	if(tileX > 4) tileX = 0;

}

void Fire::OnCollision(GameObject * go, LevelManager * game) {

	if(lifeTime == -1) lifeTime = 145;

	if(go != spawner && dynamic_cast<Enemy *>(go) != nullptr && burnDelay == 0) {
		((Enemy *) go)->AddStatus(new FireStatus(1));
		burnDelay = 60;
	}

}

bool Fire::OverrideCollision(GameObject * go) {

	return go->IsDamagable() || dynamic_cast<Player *>(go) != nullptr;

}
