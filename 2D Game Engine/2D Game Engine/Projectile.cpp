#include "Projectile.h"

#include "Ember.h"
#include <cmath>


Projectile::Projectile(const char * path, float x, float y, float init_vX, float init_vY, int init_xDir, int init_yDir, GameObject * init_spawner) 
	: GameObject(path, x, y, 6, 6, 2) {

	collidable = true;
	moveable = false;
	solid = false;

	vX = init_vX;
	vY = init_vY;

	xDir = init_xDir;
	yDir = init_yDir;

	spawner = init_spawner;
	
}


Projectile::~Projectile() {}

void Projectile::Update(LevelManager * game) {
	
	if(pow(x - spawner->GetX(), 2.0f) + pow(y - spawner->GetY(), 2.0f) > pow(maxDistance, 2)) dead = true;

}

void Projectile::OnCollision(GameObject * go, LevelManager * game) {

	if(go != spawner) {
		dead = true;
		go->DealDamage(damage, game, this);
	}

}

bool Projectile::OverrideCollision(GameObject * go) {

	return go == spawner || dynamic_cast<Particle *>(go) != nullptr;

}
