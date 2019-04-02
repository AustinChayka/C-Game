#include "Soul.h"

Soul::Soul() : Item("assets/Items/Soul.png", "Lost Soul", "new potential") {}

Soul::~Soul() {}

void Soul::OnPickup(LevelManager * game, Player * p) {

	p->SetManaFatigue(p->GetMaxManaFatigue() + 5);
	p->SetManaRegen(p->GetManaRegen() + .04f);

}
