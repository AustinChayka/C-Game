#include "RestartButton.h"

#include "LevelManager.h"

RestartButton::RestartButton(float x, float y, int width, int height, float scale) :
	Button(x, y, width, height, "Restart", scale)  {}

RestartButton::~RestartButton() {}

void RestartButton::OnHold(StateManager * sm, MenuState * m) {}

void RestartButton::OnPress(StateManager * sm, MenuState * m) {}

void RestartButton::OnRelease(StateManager * sm, MenuState * m) {

	sm->SetLevelManager(new LevelManager());
	sm->GetLevelManager()->LoadLevel(0);
	Game::gui->SetPlayer(LevelManager::player);
	sm->ChangeState(1);

}
