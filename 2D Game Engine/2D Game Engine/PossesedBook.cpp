#include "PossesedBook.h"

#include "ConfusedStatus.h"
#include "Player.h"
#include "Corpse.h"

PossesedBook::PossesedBook(float x, float y) : Enemy("assets/Enemies/PossesedBook.png", x, y, 20, 13, 3, 2) {

	collidable = true;
	solid = false;
	moveable = false;

}

PossesedBook::~PossesedBook() {}

void PossesedBook::Update(LevelManager * game) {
	
	Enemy::Update(game);

	if(target == nullptr) for(auto go : *game->GetObjects()) if(dynamic_cast<Player*>(go) != nullptr) {
		target = go;
		break;
	} else if(!target || target->IsDead()) target = nullptr;

	if(target == nullptr) return;

	float dX = target->GetXCenter() - x, dY = target->GetYCenter() - y;

	vX = 7 * dX / (abs(dX) + abs(dY));
	vY = 7 * dY / (abs(dX) + abs(dY));

	tileX += tileDir * .2f;
	if(tileX >= 3) {
		tileX = 2.8f;
		tileDir = -1;
	} else if(tileX < 0) {
		tileX = 0;
		tileDir = 1;
	}

}

void PossesedBook::OnCollision(GameObject * go, LevelManager * game) {

	go->DealDamage(1, game, this);

	if(dynamic_cast<Player *>(go) != nullptr) {
		((Player *)go)->AddStatus(new ConfusedStatus(1));
		DealDamage(health, game, nullptr);
	}

}

void PossesedBook::OnDeath(LevelManager * game, GameObject * go) {

	Enemy::OnDeath(game, go);

	game->AddObject(new Corpse("assets/Enemies/PossesedBook.png", x, y, 20, 8, 0, 0, 2));

}
