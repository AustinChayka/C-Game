#include "ControllsButton.h"

ControllsButton::ControllsButton(float x, float y, int width, int height, float scale)  : Button(x, y, width, height, 
	"Controls", scale) {}

ControllsButton::~ControllsButton() {}

void ControllsButton::OnHold(StateManager * sm, MenuState * m) {}

void ControllsButton::OnPress(StateManager * sm, MenuState * m) {}

void ControllsButton::OnRelease(StateManager * sm, MenuState * m) {

	sm->ChangeState(4);

}
