#include "Explosion.h"

#include "Smoke.h"

Explosion::Explosion(float xCenter, float yCenter, float init_radius, int init_damage, GameObject * init_spawner, LevelManager * game) :
	GameObject(nullptr, xCenter, yCenter, NULL, NULL) {

	collidable = false;
	solid = false;
	moveable = false;

	damageable = false;

	damage = init_damage;
	spawner = init_spawner;
	radius = init_radius;

	int tempRad = (int)radius;

	for(int k = 0; k < 2; k++) {

		for(int i = -tempRad; i < tempRad; i++) for(int j = -tempRad; j < tempRad; j++)
			if(abs(tempRad * tempRad - (j * j + i * i)) <= .15 * (tempRad / 20)) {
				Smoke * s = new Smoke(x + j, y + i);
				s->SetVX(s->GetVX() + j / 30);
				s->SetVY(s->GetVY() + i / 30);
				game->AddObject(s);
			}

		tempRad -= (radius / 2);

	}
	
}

Explosion::~Explosion() {}

void Explosion::UpdateObject(LevelManager * game) {

	for(auto go : *game->GetObjects()) if(go != spawner && IsInRadius(go)) go->DealDamage(damage, game, spawner);
	
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
