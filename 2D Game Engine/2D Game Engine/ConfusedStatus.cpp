#include "ConfusedStatus.h"

#include "Player.h"

ConfusedStatus::ConfusedStatus(int i) : Status("assets/Icons/ConfusionIcon.png", i, 300) {

	maxStacks = 1;

}

ConfusedStatus::~ConfusedStatus() {}

void ConfusedStatus::OnApply(GameObject * go) {

	if(dynamic_cast<Player *>(go) == nullptr) {
		increment = 0;
		return;
	}

	Game::inputManager->FlashSaveControlLayout();
	Game::inputManager->RandomizeCommands();

}

void ConfusedStatus::OnIncrement(GameObject * go, LevelManager * game) {}

void ConfusedStatus::OnEnd(GameObject * go, LevelManager * game) {

	Game::inputManager->ResetCommands();
	
}

void ConfusedStatus::OnUpdate(GameObject * go, LevelManager * game) {}
