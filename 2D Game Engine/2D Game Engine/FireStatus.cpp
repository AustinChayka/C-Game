#include "FireStatus.h"

FireStatus::FireStatus() : Status("assets/Fire.png", 1) {

	lifeTime = 60;

}

FireStatus::~FireStatus() {}

void FireStatus::OnIncrement(GameObject * go, LevelManager * game) {

	go->DealDamage(1, game, nullptr);

}

void FireStatus::OnEnd(GameObject * go, LevelManager * game) {}
