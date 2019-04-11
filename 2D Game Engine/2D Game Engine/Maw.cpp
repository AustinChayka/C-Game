#include "Maw.h"

Maw::Maw(float x, float y) : Boss("assets/Enemies/CosmicMeatball_temp.png", x, y, 100, 100, 2, 30, "Maw") {

	solid = false;
	moveable = false;

	renderLayer = 3;

}

Maw::~Maw() {}

void Maw::Update(LevelManager * game) {

	Enemy::Update(game);

}
