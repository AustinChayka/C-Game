#include "HealthPotion.h"

#include "RegenStatus.h"

HealthPotion::HealthPotion() : UseableItem("assets/Items/HealthPotion.png", "Health Potion", "probably not poisoned") {}

HealthPotion::~HealthPotion() {}

bool HealthPotion::OnUse(LevelManager * game, Player * p) {

	if(p->GetMaxHealth() == p->GetHealth()) return false;

	int r = rand() % 6;

	p->Heal(r);
	if(r < 5) p->AddStatus(new RegenStatus(5 - r));

	return true;

}
