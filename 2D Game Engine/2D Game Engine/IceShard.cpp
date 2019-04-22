#include "IceShard.h"

IceShard::IceShard(float x, float y, float vX, float vY, int xDir, int yDir, GameObject * spawner, float init_scale) : 
	Projectile("assets/Other/IceShard.png", x, y, vX, vY, xDir, yDir, spawner) {

	scale = init_scale;
	width = 6 * scale;
	height = 6 * scale;

}

IceShard::~IceShard() {}

void IceShard::Update(LevelManager * game) {

	if(collided) {

		for(auto go : *game->GetObjects()) if(CollidesWith(go)) return;

		Projectile * shard = new IceShard(x, y, vX, vY + rand() % 5, xDir, yDir, spawner, scale * .75);
		shard->SetBounces(maxBounces);
		game->AddObject(shard);
		shard = new IceShard(x, GetYCenter(), vX, vY - rand() % 5, xDir, yDir, spawner, scale * .75);
		shard->SetBounces(maxBounces);
		game->AddObject(shard);

		dead = true;
	}

}

void IceShard::OnCollision(GameObject * go, LevelManager * game) {

	if(go == spawner || (!go->IsSolid() && !go->IsDamagable())) return;

	if(scale > 1 && go->IsDamagable()) {

		go->DealDamage(damage, game, spawner);

		collided = true;

	} else Projectile::OnCollision(go, game);

}
