#include "SpiritProjectile.h"

#include "Enemy.h"
#include "Particle.h"

SpiritProjectile::SpiritProjectile(float x, float y, float init_vX, float init_vY, int init_xDir, int init_yDir,
	GameObject * init_spawner, GameObject * init_spawn)  : Projectile("assets/Other/SpiritProjectile.png", x, y, init_vX, init_vY, init_xDir, init_yDir, 
		init_spawner) {

	spawn = init_spawn;

}

SpiritProjectile::~SpiritProjectile() {}

void SpiritProjectile::Update(LevelManager * game) {

	Projectile::Update(game);

	if(delay > 0) {
		delay--;
		return;
	}

	if(particleDelay > 0) particleDelay--;
	else {
		game->AddObject(new Particle(GetXCenter() - 3, GetYCenter() - 3, 6, 6, 99, 206, 194, 184));
		particleDelay = 12;
	}

	if(target == nullptr) for(auto go : *game->GetObjects()) if(go != spawner && DistanceToSquared(go) <= 600 * 600 &&
		dynamic_cast<Enemy *>(go) != nullptr) target = go;
	else if(!target) target = nullptr;
	
	if(target == nullptr) return;

	float dX = target->GetXCenter() - GetXCenter(),
		dY = target->GetYCenter() - GetYCenter();

	vX = 7.5f * dX / (abs(dX) + abs(dY));
	vY = 7.5f * dY / (abs(dX) + abs(dY));

}

bool SpiritProjectile::OverrideCollision(GameObject * go) {

	return Projectile::OverrideCollision(go) || go == spawn || delay > 0 || dynamic_cast<Projectile *>(go) != nullptr;

}

void SpiritProjectile::OnCollision(GameObject * go, LevelManager * game) {

	if(Projectile::OverrideCollision(go) || delay > 0 || dynamic_cast<Projectile *>(go) != nullptr) return;

	Projectile::OnCollision(go, game);

}
