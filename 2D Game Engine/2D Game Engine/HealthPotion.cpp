#include "HealthPotion.h"

HealthPotion::HealthPotion() : UseableItem("assets/Items/HealthPotion.png", "Health Potion", "probably not poisoned") {}

HealthPotion::~HealthPotion() {}

bool HealthPotion::OnUse(LevelManager * game, Player * p) {

	if(p->GetMaxHealth() == p->GetHealth()) return false;

	p->Heal(3);

	return true;

}
