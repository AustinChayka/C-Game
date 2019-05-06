#include "FireStatus.h"

#include "Smoke.h"
#include "Player.h"

FireStatus::FireStatus(int i) : Status("assets/Icons/FireIcon.png", i) {

	lifeTime = 60;

}

FireStatus::~FireStatus() {}

void FireStatus::OnApply(GameObject * go) {}

void FireStatus::OnIncrement(GameObject * go, LevelManager * game) {

	go->DealDamage(1, game);

}

void FireStatus::OnEnd(GameObject * go, LevelManager * game) {}

void FireStatus::OnUpdate(GameObject * go, LevelManager * game) {

	if(dynamic_cast<Player *>(go) != nullptr && abs(go->GetVX()) + abs(go->GetVY()) < .01f && increment > 0) {
		if(burnoutDelay > 0) burnoutDelay--;
		else increment--;
	} else burnoutDelay = 10;

	if(smokeDelay > 0) smokeDelay--;
	else {
		game->AddObject(new Smoke(go->GetXCenter(), go->GetYCenter()));
		smokeDelay = 10;
	}

}
