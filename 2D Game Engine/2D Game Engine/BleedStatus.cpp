#include "BleedStatus.h"

BleedStatus::BleedStatus(int i) : Status("assets/Icons/BleedIcon.png", i) {

	lifeTime = 20;

}

BleedStatus::~BleedStatus() {}

void BleedStatus::OnIncrement(GameObject * go, LevelManager * game) {

	go->DealDamage(increment + 1, game);

}

void BleedStatus::OnEnd(GameObject * go, LevelManager * game) {}

void BleedStatus::OnUpdate(GameObject * go, LevelManager * game) {}
