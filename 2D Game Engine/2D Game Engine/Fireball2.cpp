#include "Fireball2.h"

#include "Explosion.h"
#include "FireStatus.h"
#include "Enemy.h"

Fireball2::Fireball2(float x, float y, float vX, float vY, int xDir, int yDir, GameObject * spawner) :
	Fireball(x, y, vX, vY, xDir, yDir, spawner) {}

Fireball2::~Fireball2() {}

void Fireball2::OnCollision(GameObject * go, LevelManager * game) {

	if(go == spawner || (!go->IsSolid() && !go->IsDamagable())) return;

	if(dynamic_cast<Enemy *>(go) != nullptr) ((Enemy *)go)->AddStatus(new FireStatus(1));

	Projectile::OnCollision(go, game);
	
	game->AddObject(new Explosion(GetXCenter(), GetYCenter(), 20 * scale, 1 + (int)(scale / 5), spawner, game));

}
