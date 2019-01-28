#include "Ember.h"

#include "Fire.h"

Ember::Ember(float init_x, float init_y, float init_vX, float init_vY) : Particle(init_x, init_y, 5, 5, 255, 128, 0, 200) {

	vX = init_vX;
	vY = init_vY;

	moveable = false;

}

Ember::~Ember() {}

void Ember::OnCollision(GameObject * go, LevelManager * game) {

	int wall = GetCollisionWall(go);
	
	dead = true;

	game->AddObject(new Fire(x, y - 10, (int)(2.5 * width / 5)));

}

void Ember::Update(LevelManager * game) {

	Particle::Update(game);

	vY += .3f;

}
