#include "Fire.h"

#include "Player.h"
#include "FireStatus.h"

int Fire::max = 50;
int Fire::current = 0;

Fire::Fire(float init_x, float init_y, float scale, GameObject * init_spawner) : GameObject("assets/Other/Fire.png", init_x, init_y, 10, 10, scale) {
	
	current++;

	collidable = true;
	moveable = true;
	solid = false;
	
	tileX = rand() % 4;

	spawner = init_spawner;

	renderLayer = 2;

	grav = .1f;

	if(dynamic_cast<Player *>(spawner) != nullptr) SDL_SetTextureAlphaMod(texture, 180);

}

Fire::~Fire() {
	
	current--;

}

void Fire::Update(LevelManager * game) {

	if(current >= max) {
		dead = true;
		return;
	}

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