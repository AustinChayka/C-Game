#include "ExitButton.h"

ExitButton::ExitButton(float x, float y, int width, int height, float scale) : 
	Button(x, y, width, height, "Exit", scale) {}

ExitButton::~ExitButton() {}

void ExitButton::OnHold(StateManager * sm, MenuState * m) {}

void ExitButton::OnPress(StateManager * sm, MenuState * m) {}

void ExitButton::OnRelease(StateManager * sm, MenuState * m) {

	Game::running = false;

}
