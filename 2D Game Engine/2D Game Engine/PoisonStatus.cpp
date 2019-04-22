#include "PoisonStatus.h"

PoisonStatus::PoisonStatus(int i) : Status("assets/Icons/PoisonIcon.png", i) {

	maxStacks = 10;
	lifeTime = 60 * 5;

}

PoisonStatus::~PoisonStatus() {}

void PoisonStatus::OnApply(GameObject * go) {}

void PoisonStatus::OnIncrement(GameObject * go, LevelManager * game) {}

void PoisonStatus::OnEnd(GameObject * go, LevelManager * game) {}

void PoisonStatus::OnUpdate(GameObject * go, LevelManager * game) {

	if(delay > 0) delay--;
	
	if(increment == maxStacks && delay == 0) {
		go->DealDamage(3, game);
		delay = 20;
	}

}
