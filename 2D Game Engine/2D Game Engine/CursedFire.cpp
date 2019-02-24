#include "CursedFire.h"

CursedFire::CursedFire(float x, float y, float scale) : GameObject("assets/CursedFire.png", x, y, 10, 10, scale) {

	collidable = true;
	moveable = true;
	solid = false;

	tileX = rand() % 4;

	renderLayer = 2;

}

CursedFire::~CursedFire() {



}

void CursedFire::Update(LevelManager * game) {

	if (lifeTime == 0) dead = true;
	else if (lifeTime != -1) lifeTime -= 1;

	if(!grounded) vY += .1f;

	tileX += .1f;
	if (tileX > 4) tileX = 0;

}

void CursedFire::OnCollision(GameObject * go, LevelManager * game) {

	if (lifeTime == -1) lifeTime = 145;
	
}

bool CursedFire::OverrideCollision(GameObject * go) {

	return go->IsDamagable();

}
