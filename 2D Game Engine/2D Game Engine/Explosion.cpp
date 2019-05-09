#include "Explosion.h"

#include "Smoke.h"
#include "Enemy.h"
#include "FireStatus.h"

Explosion::Explosion(float xCenter, float yCenter, float init_radius, int init_damage, GameObject * init_spawner, LevelManager * game) :
	GameObject(nullptr, xCenter, yCenter, NULL, NULL) {

	collidable = false;
	solid = false;
	moveable = false;

	damageable = false;

	damage = init_damage;
	spawner = init_spawner;
	radius = init_radius;

	for(int i = -radius; i < radius; i++) for(int j = -radius; j < radius; j++)
		if(radius * radius - (j * j + i * i) > 0 && rand() % (int)(radius * 3) == 0) {
			Smoke * s = new Smoke(x + j, y + i);
			s->SetFadeSpeed(1);
			game->AddObject(s);
		}
	
}

Explosion::~Explosion() {}

void Explosion::UpdateObject(LevelManager * game) {

	for(auto go : *game->GetObjects()) if(go != spawner && IsInRadius(go)) {
		go->DealDamage(damage, game, this);
		if(dynamic_cast<Enemy *>(go) != nullptr) ((Enemy *)go)->AddStatus(new FireStatus(3));
	}
	
	dead = true;

}

void Explosion::Update(LevelManager * game) {}

void Explosion::RenderObject() {}

bool Explosion::IsInRadius(GameObject * go) {
		
	return x - radius < go->GetX() + go->GetWidth() &&
		x + radius > go->GetX() &&
		y - radius < go->GetY() + go->GetHeight() &&
		y + radius > go->GetY();

}
