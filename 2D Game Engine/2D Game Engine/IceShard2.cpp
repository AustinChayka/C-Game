#include "IceShard2.h"

#include "ChilledStatus.h"
#include "Enemy.h"

IceShard2::IceShard2(float x, float y, float vX, float vY, int xDir, int yDir, GameObject * spawner, float init_scale) :
	IceShard(x, y, vX, vY, xDir, yDir, spawner, init_scale) {}

IceShard2::~IceShard2() {}

void IceShard2::Update(LevelManager * game) {

	Projectile::Update(game);

	if(collided) {

		for(auto go : *game->GetObjects()) if(CollidesWith(go)) return;

		Projectile * shard = new IceShard2(x, y - height / 2, vX, vY + rand() % 5, xDir, yDir, spawner, scale * .75);
		shard->SetBounces(maxBounces);
		game->AddObject(shard);
		shard = new IceShard2(x, GetYCenter() + height / 2, vX, vY - rand() % 5, xDir, yDir, spawner, scale * .75);
		shard->SetBounces(maxBounces);
		game->AddObject(shard);
		shard = new IceShard2(x, y + height, vX, vY, xDir, yDir, spawner, scale * .75);
		shard->SetBounces(maxBounces);
		game->AddObject(shard);

		dead = true;
	}

	if(delay > 0) delay--;
	else {
		int i = rand() % 2;
		game->AddObject(new IceShard2(x, y + (i == 0 ? -height / 2 : height), vX,
			vY + (i == 0 ? -(rand() % 5) : rand() % 5), xDir, yDir, spawner, scale / 2));
		delay = 30;
	}

}

void IceShard2::OnCollision(GameObject * go, LevelManager * game) {

	if(dynamic_cast<IceShard2 *>(go) != nullptr) return;

	IceShard::OnCollision(go, game);

	if(go != spawner && dynamic_cast<Enemy *>(go) != nullptr) ((Enemy *)go)->AddStatus(new ChilledStatus(1));

}
