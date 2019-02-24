#include "Ember.h"

#include "Fire.h"

Ember::Ember(float init_x, float init_y, float init_vX, float init_vY, GameObject * init_spawner) : Particle(init_x, init_y, 5, 5, 255, 128, 0, 200) {

	vX = init_vX;
	vY = init_vY;

	moveable = false;
	collidable = true;

	spawner = init_spawner;

}

Ember::~Ember() {}

void Ember::OnCollision(GameObject * go, LevelManager * game) {

	if(go == spawner || !go->IsSolid()) return;
		
	dead = true;

	game->AddObject(new Fire(x, y - 10, (int)(2.5 * width / 5), spawner));

}

void Ember::Update(LevelManager * game) {

	Particle::Update(game);

	vY += .3f;

}
