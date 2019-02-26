#include "Slime.h"

Slime::Slime(float x, float y, int size) : GameObject("assets/Slime.png", x, y, 20, 17, size) {

	damageable = true;
	health = size;

	collidable = true;
	solid = true;
	moveable = true;

	decceleration = 1.5f;
	grav = .8f;

}

Slime::~Slime() {}

void Slime::Update(LevelManager * game) {

	for(auto go : *game->GetObjects()) if(dynamic_cast<Player*>(go) != nullptr && DistanceToSquared(go) < 40000) {

		target = go;

	}

	if(jumpDelay == 0) {
		if(grounded) {
			vX = target == nullptr ? (10 * (rand() % 2 == 0 ? -1 : 1)) : (target->GetX() > x ? 10 : -10);
			vY = -15;
			jumpDelay = 1 * 60;
		}
	} else jumpDelay--;

	if(health < scale / 2 && grounded) {
		vY = -15;
		split = true;
	}

	if(split && vY >= 0 && (int)(scale / 2) >= 1) {
		Slime * s = new Slime(GetXCenter() - 20 * ((int)(scale / 2) - 1), y, (int)(scale / 2) + 1);
		s->SetVX(-12);
		game->AddObject(s);
		s = new Slime(GetXCenter() + 1, y, (int) (scale / 2) + 1);
		s->SetVX(12);
		game->AddObject(s);
		dead = true;
	}
	
}

void Slime::OnCollision(GameObject * go, LevelManager * game) {
	
	if(dynamic_cast<Slime *>(go) == nullptr) go->DealDamage(1, game, this);

}

void Slime::OnDeath(LevelManager * game) {

	if((int) (scale / 2) >= 1) {

		game->AddObject(new Slime(x, y, (int)(scale / 2)));
		game->AddObject(new Slime(x + width - width * (int)(scale / 2), y, (int)(scale / 2)));

	}

}

bool Slime::OverrideCollision(GameObject * go) {

	return dynamic_cast<Slime *>(go) != nullptr;

}
