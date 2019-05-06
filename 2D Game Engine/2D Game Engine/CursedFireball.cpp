#include "CursedFireball.h"

#include "Particle.h"
#include "CursedFire.h"
#include "Spirit.h"

CursedFireball::CursedFireball(float x, float y, float init_vX, float init_vY, int init_xDir, int init_yDir, GameObject * init_spawner) :
	Projectile("assets/Other/CursedFireball.png", x, y, init_vX, init_vY, init_xDir, init_yDir, init_spawner) {
	
	damage = 2;

}

CursedFireball::~CursedFireball() {}

void CursedFireball::Update(LevelManager * game) {

	Projectile::Update(game);

	if (particleTimer == 0) {
		game->AddObject(new Particle(GetXCenter() - 3, GetYCenter() - 3, 6, 6, 99, 206, 194, 184));
		particleTimer = particleDelay;
	}
	else particleTimer--;

}

void CursedFireball::OnCollision(GameObject * go, LevelManager * game) {

	if(go == spawner || (!go->IsSolid() && !go->IsDamagable()) || dynamic_cast<Spirit *>(go) != nullptr) return;

	Projectile::OnCollision(go, game);

	game->AddObject(new CursedFire(x, y - 10, 3, spawner));
	game->AddObject(new CursedFire(x - 10, y - 10, 2, spawner));
	game->AddObject(new CursedFire(x + 20, y - 10, 2, spawner));

}
