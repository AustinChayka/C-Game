#include "CursedFireStatus.h"

CursedFireStatus::CursedFireStatus(int i) : Status("assets/Icons/CursedFireIcon.png", i) {}

CursedFireStatus::~CursedFireStatus() {}

void CursedFireStatus::OnIncrement(GameObject * go, LevelManager * game) {

	go->DealDamage(2, game);

}

void CursedFireStatus::OnEnd(GameObject * go, LevelManager * game) {}

void CursedFireStatus::OnUpdate(GameObject * go, LevelManager * game) {}
