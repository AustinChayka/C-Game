#include "Snowman.h"

#include "Player.h"
#include "Snowball.h"

Snowman::Snowman(float x, float y) : Enemy("assets/Snowman.png", x, y, 20, 39, 3, 4) {
	
	collidable = true;
	solid = false;
	moveable = true;
	
}

Snowman::~Snowman() {}

void Snowman::Update(LevelManager * game) {

	Enemy::Update(game);

	if(delay > 0) delay--;
	
	if(target == nullptr) for(auto go : *game->GetObjects()) if(dynamic_cast<Player*>(go) != nullptr && OnScreen()) {

		target = go;

	}	

	if(target == nullptr) return;

	if(delay == 0 && DistanceToSquared(target) < 500 * 500) {

		game->AddObject(new Snowball(GetXCenter(), GetYCenter(), (target->GetXCenter() - GetXCenter()) / 30,
			.5f * .8f * -30, x > target->GetX() ? -1 : 1, 0, this));
		delay = 90;

	}

}

bool Snowman::OverrideCollision(GameObject * go) {

	return dynamic_cast<Enemy *>(go) != nullptr;

}
