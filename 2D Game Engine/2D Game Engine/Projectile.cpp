#include "Projectile.h"

#include "Ember.h"
#include <cmath>
#include "Player.h"


Projectile::Projectile(const char * path, float x, float y, float init_vX, float init_vY, int init_xDir, int init_yDir, GameObject * init_spawner) 
	: GameObject(path, x, y, 6, 6, 2) {

	collidable = true;
	moveable = false;
	solid = false;

	vX = spawnVX = init_vX;
	vY = spawnVY = init_vY;

	xDir = init_xDir;
	yDir = init_yDir;

	spawner = init_spawner;

	spawnX = x;
	spawnY = y;
	
}


Projectile::~Projectile() {}

void Projectile::Update(LevelManager * game) {

	if(spawner->IsDead()) spawner = nullptr;
	
	lifeTime++;
	distance += sqrt(pow(vX, 2) + pow(vY, 2));

	if(spawner == nullptr || !spawner) return;

	if(dynamic_cast<Player *>(spawner) != nullptr) ((Player *) spawner)->UpdateProjectile(game, this);
	
	if(pow(x - spawner->GetX(), 2.0f) + pow(y - spawner->GetY(), 2.0f) > pow(maxDistance, 2)) dead = true;


}

void Projectile::OnCollision(GameObject * go, LevelManager * game) {

	if(go != spawner) {
		dead = true;
		go->DealDamage(damage, game, spawner);
	}

}

bool Projectile::OverrideCollision(GameObject * go) {

	return go == spawner || dynamic_cast<Particle *>(go) != nullptr;

}

float Projectile::DistanceTraveled() {

	return distance;

}

float Projectile::GetSpawnX() {

	return spawnX;

}

float Projectile::GetSpawnY() {

	return spawnY;

}

float Projectile::GetSpawnVX() {
	return spawnVX;
}

float Projectile::GetSpawnVY() {
	return spawnVY;
}

int Projectile::GetLifeTime() {

	return lifeTime;

}

void Projectile::SetSpawner(GameObject * go) {

	spawner = go;

}
