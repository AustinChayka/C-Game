#include "HealthPotion.h"

#include "RegenStatus.h"

HealthPotion::HealthPotion() : UseableItem("assets/Items/HealthPotion.png", "Health Potion", "probably not poisoned") {}

HealthPotion::~HealthPotion() {}

bool HealthPotion::OnUse(LevelManager * game, Player * p) {

	if(p->GetMaxHealth() == p->GetHealth()) return false;

	int power = rand() % (int)(p->GetMaxHealth() * .25f) + (int)(p->GetMaxHealth() * .5f), r = rand() % power;

	p->Heal(r);
	p->AddStatus(new RegenStatus(power - r));

	return true;

}
