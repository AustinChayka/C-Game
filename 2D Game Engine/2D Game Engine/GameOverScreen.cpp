#include "GameOverScreen.h"

#include "ExitButton.h"
#include "RestartButton.h"

GameOverScreen::GameOverScreen() : MenuState() {
	
	text = TextureManager::LoadText(Game::renderer, 24, {255, 255, 255}, "Game Over");

	destRect.x = Game::width / 2 - 350;;
	destRect.y = 50;
	destRect.w = 600;
	destRect.h = 100;

	buttons.clear();
	buttons.push_back(new ExitButton(Game::width / 2, 400, 150, 50, 2));
	buttons.push_back(new RestartButton(Game::width / 2 - 400, 400, 150, 50, 2));

}

GameOverScreen::~GameOverScreen() {



}

void GameOverScreen::Update(StateManager * sm) {

	MenuState::Update(sm);

}

void GameOverScreen::Render() {

	MenuState::Render();

	SDL_RenderCopy(Game::renderer, text, NULL, &destRect);

}
