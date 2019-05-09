#include "KeybindButton.h"

#include <iostream>

KeybindButton::KeybindButton(float x, float y, int width, int height, const char * buttonText, 
	float scale, int init_command) : Button(x, y, width, height, buttonText, scale) {

	command = init_command;

}

KeybindButton::~KeybindButton() {}

void KeybindButton::Update(StateManager * sm, MenuState * m) {

	Button::Update(sm, m);

	if(listening && Game::inputManager->GetLastEvent()->type == SDL_KEYDOWN) {

		Game::inputManager->RebindCommand(command, Game::inputManager->GetLastEvent()->key.keysym.sym);
		listening = false;
		SDL_DestroyTexture(text);
		text = TextureManager::LoadText(Game::renderer, 24, {255, 255, 255},
			SDL_GetKeyName(Game::inputManager->GetLastEvent()->key.keysym.sym));

	}

}

void KeybindButton::OnHold(StateManager * sm, MenuState * m) {}

void KeybindButton::OnPress(StateManager * sm, MenuState * m) {}

void KeybindButton::OnRelease(StateManager * sm, MenuState * m) {

	if(!listening) listening = true;
	SDL_DestroyTexture(text);
	text = TextureManager::LoadText(Game::renderer, 24, {255, 255, 255}, "...");

}
