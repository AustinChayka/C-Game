#include "BloatedDoll.h"

#include "Explosion.h"

BloatedDoll::BloatedDoll() : Item("assets/Items/BloatedDoll.png", "Bloated Doll", "corpse explosion") {}

BloatedDoll::~BloatedDoll() {}

void BloatedDoll::OnKill(LevelManager * game, Player * p, GameObject * go) {

	game->AddObject(new Explosion(go->GetXCenter(), go->GetYCenter(), go->GetMaxHealth() < 20 ? go->GetMaxHealth() * 40 : 800,
		1 + go->GetMaxHealth() < 20 ? go->GetMaxHealth() / 2 : 10, p, game));

}
