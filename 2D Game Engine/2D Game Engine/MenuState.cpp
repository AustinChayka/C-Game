#include "MenuState.h"

#include "Game.h"

#include "PlayButton.h"
#include "ExitButton.h"

MenuState::MenuState() {

	text = TextureManager::LoadText(Game::renderer, 24, {255, 255, 255}, "[Insert Title]");

	destRect.x = 50;
	destRect.y = 50;
	destRect.w = 600;
	destRect.h = 100;

	buttons.push_back(new PlayButton(50, 400, 150, 50, 2));
	buttons.push_back(new ExitButton(400, 400, 150, 50, 2));

}

MenuState::~MenuState() {}

void MenuState::Update(StateManager * sm) {

	for(auto b : buttons) b->Update(sm, this);
	
}

void MenuState::Render() {

	SDL_RenderCopy(Game::renderer, text, NULL, &destRect);

	for(auto b : buttons) b->Render();

}
