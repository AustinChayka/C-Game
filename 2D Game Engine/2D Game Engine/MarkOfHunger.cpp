#include "MarkOfHunger.h"

MarkOfHunger::MarkOfHunger()  : Item("assets/Items/MarkOfHunger.png", "Mark of Hunger", "feed your soul") {}

MarkOfHunger::~MarkOfHunger() {}

void MarkOfHunger::OnDamageDelt(LevelManager * game, Player * p, GameObject * go) {

	if(rand() % 5 == 0) p->Heal(1);

}
