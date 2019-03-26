#include "Hammer.h"

#include "NailObject.h"

Hammer::Hammer(float x, float y) : GameObject("assets/Hammer.png", x, y, 30, 50, 4) {

	collidable = true;
	solid = true;
	moveable = false;

	grav = 0.5f;

}

Hammer::~Hammer() {}

void Hammer::Update(LevelManager * game) { 

	if(collided) {
		if(delay > 0) delay--;
		else dead = true;
	}

}

bool Hammer::OverrideCollision(GameObject * go) {

	return dynamic_cast<NailObject *>(go) == nullptr || !go->IsDamagable();

}

void Hammer::OnCollision(GameObject * go, LevelManager * game) {

	if(collided) return;

	if(dynamic_cast<NailObject *>(go) != nullptr) {
		collided = true;
		vX = vY = 0;
		grav = 0;
		y = go->GetY() + go->GetHeight() - height;
	}
	else if(go->IsDamagable()) go->DealDamage(100, game);

}
