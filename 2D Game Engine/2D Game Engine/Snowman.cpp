#include "Snowman.h"

#include "Player.h"
#include "Snowball.h"

Snowman::Snowman(float x, float y) : Enemy("assets/Enemies/Snowman.png", x, y, 30, 39, 3, 4) {
	
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
		break;
	}  else if(!target || target->IsDead()) target = nullptr;

	if(target == nullptr) return;

	tileX = delay < 40 && delay > 0 ? (40 - delay) / 40.0f * 5 : 0;

	if(delay == 0 && OnScreen()) {

		if(target->GetY() <= y)
			game->AddObject(new Snowball(x + 3, y + 1, (target->GetXCenter() - GetXCenter()) / 30,
				.5f * .8f * -30, x > target->GetX() ? -1 : 1, 0, this));
		else 
			game->AddObject(new Snowball(x + 3, y + 1, (target->GetXCenter() - GetXCenter()) / 20,
				(target->GetYCenter() - GetYCenter()) / 180, x > target->GetX() ? -1 : 1, 0, this));
		delay = 90;

	}

}

bool Snowman::OverrideCollision(GameObject * go) {

	return dynamic_cast<Enemy *>(go) != nullptr;

}
