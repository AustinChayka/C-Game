#include "MenuState.h"

#include "Game.h"

MenuState::MenuState() {}

MenuState::~MenuState() {}

void MenuState::Update(StateManager * sm) {
	
}

void MenuState::Render() {

	SDL_SetRenderDrawColor(Game::renderer, 255, 0, 0, 255);
	SDL_Rect rect;
	rect.x = 100;
	rect.y = 50;
	rect.w = 200;
	rect.h = 100;
	SDL_RenderDrawRect(Game::renderer, &rect);

}
