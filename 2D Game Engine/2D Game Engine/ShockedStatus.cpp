#include "ShockedStatus.h"

#include "Enemy.h"

ShockedStatus::ShockedStatus(int i) : Status("assets/Icons/ShockedIcon.png", i, 20) {

	maxStacks = 5;

}

ShockedStatus::~ShockedStatus() {}

void ShockedStatus::OnApply(GameObject * go) {}

void ShockedStatus::OnIncrement(GameObject * go, LevelManager * game) {

	go->DealDamage(1, game);
	
}

void ShockedStatus::OnEnd(GameObject * go, LevelManager * game) {}

void ShockedStatus::OnUpdate(GameObject * go, LevelManager * game) {

	if(transferDelay > 0) transferDelay--;
	else {
		for(auto goTarget : *game->GetObjects()) if(go->CollidesWith(goTarget)
			&& dynamic_cast<Enemy *>(goTarget) != nullptr) {
			((Enemy *)goTarget)->AddStatus(new ShockedStatus(1));
			transferDelay = 30;
			break;
		}
	}
}
