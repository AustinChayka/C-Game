#include "GamblingChip.h"

GamblingChip::GamblingChip() : Item("assets/Items/GamblingChip.png", "Gambling Chip", "double or nothing"){}

GamblingChip::~GamblingChip() {}

void GamblingChip::OnPickup(LevelManager * game, Player * p) {

	Item::OnPickup(game, p);

	p->SetLuck(p->GetLuck() + 10);

}

void GamblingChip::OnShotFired(LevelManager * game, Player * p, Projectile *& proj) {

	if(rand() % 100 <= p->GetLuck()) proj->SetDamage(proj->GetDamage() * 2);
	else proj->SetDamage(0);

}
