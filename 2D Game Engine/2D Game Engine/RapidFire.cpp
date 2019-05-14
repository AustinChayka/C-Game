#include "RapidFire.h"

RapidFire::RapidFire() : Item("assets/Items/BagOfMarbles.png", "Bag of Marbles", "quantity over quality") {}

RapidFire::~RapidFire() {}

void RapidFire::OnPickup(LevelManager * game, Player * p) {

	Item::OnPickup(game, p);

	p->SetShotCost(p->GetShotCost() / 1.2f);
	p->SetShotDelay((int)(p->GetShotDelay() / 3));

}

void RapidFire::OnShotFired(LevelManager * game, Player * p, Projectile *& proj) {

	proj->SetVY(proj->GetVY() + (rand() % 700 - 350) / 100.0f);
	proj->SetScale(proj->GetScale() * .75f);

}
