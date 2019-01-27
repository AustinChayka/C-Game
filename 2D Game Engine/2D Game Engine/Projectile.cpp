#include "Projectile.h"

#include "Ember.h"
#include <cmath>


Projectile::Projectile(float x, float y, float init_vX, float init_vY, int init_xDir, int init_yDir, GameObject * init_spawner) 
	: GameObject("assets/Projectile.png", x - 3, y - 3, 6, 6, 2) {

	collidable = false;
	moveable = false;

	vX = init_vX;
	vY = init_vY;

	xDir = init_xDir;
	yDir = init_yDir;

	spawner = init_spawner;
	
}


Projectile::~Projectile() {}

void Projectile::Update(LevelManager * game) {
	
	vY += .02f;

	if(particleDelay == 0) {
		game->AddObject(new Ember(x, GetYCenter(), rand() % -5, rand() % 10 - 5));
		particleDelay = 3;
	} else particleDelay--;

	if(pow(x - spawner->GetX(), 2.0f) + pow(y - spawner->GetY(), 2.0f) > pow(maxDistance, 2)) dead = true;

}

void Projectile::OnCollision(GameObject * go) {

	if(go != spawner) dead = true;

}
