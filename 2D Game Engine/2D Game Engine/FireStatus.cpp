#include "FireStatus.h"

FireStatus::FireStatus(int i) : Status("assets/Icons/FireIcon.png", i) {

	lifeTime = 60;

}

FireStatus::~FireStatus() {}

void FireStatus::OnApply(GameObject * go) {}

void FireStatus::OnIncrement(GameObject * go, LevelManager * game) {

	go->DealDamage(1, game);

}

void FireStatus::OnEnd(GameObject * go, LevelManager * game) {}

void FireStatus::OnUpdate(GameObject * go, LevelManager * game) {}
