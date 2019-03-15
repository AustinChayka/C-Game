#include "Snowman.h"

Snowman::Snowman(float x, float y) : Enemy("assets/Snowman.png", x, y, NULL, NULL, 3, 4) {
	
	collidable = true;
	solid = true;
	moveable = true;

	grav = .8f;

}

Snowman::~Snowman() {}

void Snowman::Update(LevelManager * game) {

	Enemy::Update(game);

}
