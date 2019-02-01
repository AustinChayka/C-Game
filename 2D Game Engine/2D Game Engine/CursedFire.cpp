#include "CursedFire.h"

CursedFire::CursedFire(float x, float y, float scale) : GameObject("assets/CursedFire.png", x, y, 10, 10, scale) {

	moveable = false;

}

CursedFire::~CursedFire() {



}

void CursedFire::Update(LevelManager * game) {

	if (lifeTime == 0) dead = true;
	else if (lifeTime != -1) lifeTime -= 1;

	if (!grounded) vY += .1f;

	tileX += .1f;
	if (tileX > 4) tileX = 0;

}

void CursedFire::OnCollision(GameObject * go, LevelManager * game) {

	if (lifeTime == -1) lifeTime = 145;

	if (go->IsSolid() && GetCollisionWall(go) == BOTTOM) {
		grounded = true;
		vY = 0;
		LockY(go);
	}
	else grounded = false;

	if (go->IsSolid()) go->DealDamage(2);

}
