#include "MenuState.h"

#include "Game.h"

MenuState::MenuState() {

	text = TextureManager::LoadText(Game::renderer, 24, {255, 255, 255}, "Press [Esc] to continue");

	destRect.x = 50;
	destRect.y = 50;
	destRect.w = 600;
	destRect.h = 100;

}

MenuState::~MenuState() {}

void MenuState::Update(StateManager * sm) {
	
}

void MenuState::Render() {

	SDL_RenderCopy(Game::renderer, text, NULL, &destRect);

}
