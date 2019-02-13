#include "PlayButton.h"

PlayButton::PlayButton(float x, float y, int width, int height, float scale) : Button(x, y, width, height, "Play", scale) {



}

PlayButton::~PlayButton() {



}

void PlayButton::OnHold(StateManager * sm, MenuState * m) {



}

void PlayButton::OnPress(StateManager * sm, MenuState * m) {



}

void PlayButton::OnRelease(StateManager * sm, MenuState * m) {

	sm->ChangeState(1);

}
