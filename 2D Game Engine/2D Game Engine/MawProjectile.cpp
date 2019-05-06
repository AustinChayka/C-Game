#include "MawProjectile.h"

#include "Enemy.h"
#include "PoisonStatus.h"
#include "ChilledStatus.h"

MawProjectile::MawProjectile(float x, float y, float init_vX, float init_vY, int init_xDir, int init_yDir, GameObject * init_spawner) : 
	Projectile("assets/Other/MawProjectile.png", x, y, init_vX, init_vY, init_xDir, init_yDir, init_spawner) {

	damage = 1;

}

MawProjectile::~MawProjectile() {}

void MawProjectile::Update(LevelManager * game) {

	Projectile::Update(game);

	if(particleDelay > 0) particleDelay--;


}

void MawProjectile::OnCollision(GameObject * go, LevelManager * game) {

	if(go == spawner || (!go->IsSolid() && !go->IsDamagable())) return;

	Projectile::OnCollision(go, game);

	if(dynamic_cast<Enemy *>(go) != nullptr) {
		((Enemy *)go)->AddStatus(new ChilledStatus(1));
		((Enemy *)go)->AddStatus(new PoisonStatus(2));
	}

}
