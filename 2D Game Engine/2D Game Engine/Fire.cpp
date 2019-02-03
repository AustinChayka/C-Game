#include "Fire.h"

Fire::Fire(float init_x, float init_y, float scale) : GameObject("assets/Fire.png", init_x, init_y, 10, 10, scale) {

	moveable = false;
	
	tileX = rand() % 4;

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

	if(go->IsSolid() && GetCollisionWall(go) == BOTTOM) {
		grounded = true;
		vY = 0;
		LockY(go);
	} else grounded = false;

	if(go->IsSolid()) go->DealDamage(1);

}
