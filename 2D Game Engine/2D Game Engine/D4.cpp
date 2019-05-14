#include "D4.h"

D4::D4() : Item("assets/Items/D4.png", "D4", "heal on crits") {}

D4::~D4() {}

void D4::OnPickup(LevelManager * game, Player * p) {

	Item::OnPickup(game, p);

	p->SetCritValue(p->GetCritValue() + 0.5f);

}

void D4::OnDamageDelt(LevelManager * game, Player * p, GameObject * go, bool crit) {

	if(crit) p->Heal(2);

}
