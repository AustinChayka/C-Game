#include "CursedFireStatus.h"

#include "Smoke.h"

CursedFireStatus::CursedFireStatus(int i) : Status("assets/Icons/CursedFireIcon.png", i) {}

CursedFireStatus::~CursedFireStatus() {}

void CursedFireStatus::OnApply(GameObject * go) {}

void CursedFireStatus::OnIncrement(GameObject * go, LevelManager * game) {

	go->DealDamage(2, game);

}

void CursedFireStatus::OnEnd(GameObject * go, LevelManager * game) {}

void CursedFireStatus::OnUpdate(GameObject * go, LevelManager * game) {

	if(abs(go->GetVX()) + abs(go->GetVY()) < .01f && increment > 0) {
		if(burnoutDelay > 0) burnoutDelay--;
		else increment--;
	} else burnoutDelay = 10;
	
	if(smokeDelay > 0) smokeDelay--;
	else {		
		game->AddObject(new Smoke(go->GetXCenter(), go->GetYCenter()));
		smokeDelay = 10;
	}

}
