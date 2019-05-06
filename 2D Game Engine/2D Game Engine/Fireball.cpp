#include "Fireball.h"

#include "Pot.h"
#include "FireStatus.h"
#include "Enemy.h"
#include "Boss.h"

Fireball::Fireball(float x, float y, float init_vX, float init_vY, int init_xDir, int init_yDir, GameObject * init_spawner) :
	Projectile("assets/Other/Fireball.png", x, y, init_vX, init_vY, init_xDir, init_yDir, init_spawner) {

	damage = 1;

}

Fireball::~Fireball() {}

void Fireball::Update(LevelManager * game) {

	Projectile::Update(game);

	if(embers) {
		if(particleDelay == 0) {
			game->AddObject(new Ember(GetXCenter(), GetYCenter(), rand() % 3 * -xDir, rand() % 10 - 5, spawner));
			particleDelay = 3;
		} else particleDelay--;
	}

}

void Fireball::OnCollision(GameObject * go, LevelManager * game) {

	if(go == spawner || (dynamic_cast<Pot *>(go) == nullptr && !go->IsSolid() && !go->IsDamagable())) return;

	if(dynamic_cast<Enemy *>(go) != nullptr) ((Enemy *)go)->AddStatus(new FireStatus(1));

	Projectile::OnCollision(go, game);
	
	if(embers) {
		for(int i = 0; i < rand() % 7 + 3; i++)
			game->AddObject(new Ember(xDir == 1 ? x : x + width, GetYCenter(), (rand() % 5 + 2) * -xDir, rand() % 10 - 5, spawner));
	}

}