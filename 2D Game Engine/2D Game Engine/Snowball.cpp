#include "Snowball.h"

#include "Enemy.h"
#include "ChilledStatus.h"
#include "Snowman.h"

Snowball::Snowball(float x, float y, float vX, float vY, int xDir, int yDir, GameObject * spawner) : 
	Projectile("assets/Other/Snowball.png", x, y, vX, vY, xDir, yDir, spawner) {

	damage = 0;
	grav = 0.8f;

	collidable = true;

}

Snowball::~Snowball() {}

void Snowball::OnCollision(GameObject * go, LevelManager * game) {

	if(go == spawner || (!go->IsSolid() && !go->IsDamagable())) return;

	Projectile::OnCollision(go, game);
	
	if(dynamic_cast<Enemy *>(go) != nullptr) ((Enemy *) go)->AddStatus(new ChilledStatus(3));

}
