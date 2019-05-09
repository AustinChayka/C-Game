#include "RegenStatus.h"

RegenStatus::RegenStatus(int i) : Status("assets/Icons/RegenIcon.png", i, 20) {

	maxStacks = 10;

}

RegenStatus::~RegenStatus() {}

void RegenStatus::OnApply(GameObject * go) {}

void RegenStatus::OnIncrement(GameObject * go, LevelManager * game) {

	go->Heal(1);

}

void RegenStatus::OnEnd(GameObject * go, LevelManager * game) {}

void RegenStatus::OnUpdate(GameObject * go, LevelManager * game) {}
