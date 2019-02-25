#include "Fire.h"

Fire::Fire(float init_x, float init_y, float scale, GameObject * init_spawner) : GameObject("assets/Fire.png", init_x, init_y, 10, 10, scale) {

	collidable = true;
	moveable = true;
	solid = false;
	
	tileX = rand() % 4;

	spawner = init_spawner;

	renderLayer = 2;

}

Fire::~Fire() {}

void Fire::Update(LevelManager * game) {

	if(lifeTime == 0) dead = true;
	else if(lifeTime != -1) lifeTime -= 1;

	if(!grounded) vY += .1f;

	tileX += .1f;
	if(tileX > 4) tileX = 0;

}

void Fire::OnCollision(GameObject * go, LevelManager * game) {

	if(lifeTime == -1) lifeTime = 145;

	if(go != spawner && go->IsSolid()) go->DealDamage(1);

}

bool Fire::OverrideCollision(GameObject * go) {

	return go->IsDamagable();

}
