#include "Fireball.h"

#include "Pot.h"

Fireball::Fireball(float x, float y, float init_vX, float init_vY, int init_xDir, int init_yDir, GameObject * init_spawner) :
	Projectile("assets/Fireball.png", x, y, init_vX, init_vY, init_xDir, init_yDir, init_spawner) {

	damage = 1;

}

Fireball::~Fireball() {}

void Fireball::Update(LevelManager * game) {

	Projectile::Update(game);

	if(particleDelay == 0) {
		game->AddObject(new Ember(GetXCenter(), GetYCenter(), rand() % 3 * -xDir, rand() % 10 - 5, spawner));
		particleDelay = 3;
	} else particleDelay--;

}

void Fireball::OnCollision(GameObject * go, LevelManager * game) {

	if(go == spawner || (dynamic_cast<Pot *>(go) == nullptr && !go->IsSolid() && !go->IsDamagable())) return;

	Projectile::OnCollision(go, game);

	for(int i = 0; i < rand() % 7 + 3; i++)
		game->AddObject(new Ember(xDir == 1 ? x : x + width, GetYCenter(), (rand() % 5 + 2) * -xDir, rand() % 10 - 5, spawner));

}