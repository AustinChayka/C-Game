#include "GameOverScreen.h"

#include "ExitButton.h"

GameOverScreen::GameOverScreen() : MenuState() {
	
	text = TextureManager::LoadText(Game::renderer, 24, {255, 255, 255}, "Game Over");

	destRect.x = 50;
	destRect.y = 50;
	destRect.w = 600;
	destRect.h = 100;

	buttons.push_back(new ExitButton(125, 400, 150, 50, 2));

}

GameOverScreen::~GameOverScreen() {



}

void GameOverScreen::Update(StateManager * sm) {



}

void GameOverScreen::Render() {

	SDL_RenderCopy(Game::renderer, text, NULL, &destRect);

}
