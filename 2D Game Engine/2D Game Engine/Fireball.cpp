#include "Fireball.h"

Fireball::Fireball(float x, float y, float init_vX, float init_vY, int init_xDir, int init_yDir, GameObject * init_spawner) :
	Projectile("assets/Projectile.png", x, y, init_vX, init_vY, init_xDir, init_yDir, init_spawner) {}

Fireball::~Fireball() {}

void Fireball::Update(LevelManager * game) {

	Projectile::Update(game);

	if(particleDelay == 0) {
		game->AddObject(new Ember(GetXCenter(), GetYCenter(), rand() % 3 * -xDir, rand() % 10 - 5));
		particleDelay = 3;
	} else particleDelay--;

}

void Fireball::OnCollision(GameObject * go, LevelManager * game) {

	if(go == spawner) return;

	Projectile::OnCollision(go, game);

	for(int i = 0; i < rand() % 7 + 3; i++)
		game->AddObject(new Ember(xDir == 1 ? x : x + width, GetYCenter(), (rand() % 5 + 2) * -xDir, rand() % 10 - 5));

}