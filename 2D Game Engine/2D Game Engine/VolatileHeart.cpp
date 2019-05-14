#include "VolatileHeart.h"

#include "Explosion.h"

VolatileHeart::VolatileHeart() : Item("assets/Items/VolatileHeart.png", "Volatile Heart", "hazardous health") {}

VolatileHeart::~VolatileHeart() {}

void VolatileHeart::OnPickup(LevelManager * game, Player * p) {

	Item::OnPickup(game, p);

	p->SetMaxHealth(p->GetMaxHealth() + 6);
	p->Heal(6);

}

void VolatileHeart::OnDamageTaken(LevelManager * game, GameObject * go, Player * p) {

	if(rand() % 5 == 0) game->AddObject(new Explosion(p->GetXCenter(), p->GetYCenter(), 250, 3, p, game));

}
