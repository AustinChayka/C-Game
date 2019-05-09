#include "KeybindMenu.h"

#include "PlayButton.h"
#include "KeybindButton.h"

KeybindMenu::KeybindMenu() {

	SDL_DestroyTexture(text);
	text = TextureManager::LoadText(Game::renderer, 24, {255, 255, 255}, "Keybindings");

	left = TextureManager::LoadText(Game::renderer, 24, {255, 255, 255}, "left");
	right = TextureManager::LoadText(Game::renderer, 24, {255, 255, 255}, "right");
	jump = TextureManager::LoadText(Game::renderer, 24, {255, 255, 255}, "jump");
	down = TextureManager::LoadText(Game::renderer, 24, {255, 255, 255}, "down");
	shoot = TextureManager::LoadText(Game::renderer, 24, {255, 255, 255}, "shoot");
	interact = TextureManager::LoadText(Game::renderer, 24, {255, 255, 255}, "interact");
	useItem = TextureManager::LoadText(Game::renderer, 24, {255, 255, 255}, "item");
	croutch = TextureManager::LoadText(Game::renderer, 24, {255, 255, 255}, "croutch");
	dash = TextureManager::LoadText(Game::renderer, 24, {255, 255, 255}, "dash");

	for(auto b : buttons) delete b;
	buttons.clear();
	buttons.push_back(new PlayButton(Game::width / 2 - 150, 600, 150, 50, 2));
	buttons.push_back(new KeybindButton(210, 220, 50, 30, " a ", 3, InputManager::left));
	buttons.push_back(new KeybindButton(210, 320, 50, 30, " d ", 3, InputManager::right));
	buttons.push_back(new KeybindButton(210, 420, 50, 30, " w ", 3, InputManager::jump));
	buttons.push_back(new KeybindButton(560, 220, 50, 30, " d ", 3, InputManager::down));
	buttons.push_back(new KeybindButton(560, 320, 50, 30, "spc", 3, InputManager::shoot));
	buttons.push_back(new KeybindButton(596, 420, 50, 30, " e ", 3, InputManager::interact));
	buttons.push_back(new KeybindButton(910, 220, 50, 30, " q ", 3, InputManager::useItem));
	buttons.push_back(new KeybindButton(958, 320, 50, 30, "lctrl", 3, InputManager::croutch));
	buttons.push_back(new KeybindButton(910, 420, 50, 30, "lshft", 3, InputManager::croutch));
	
}

KeybindMenu::~KeybindMenu() {}

void KeybindMenu::Render() {

	MenuState::Render();

	textRect.x = 50;
	textRect.y = 220;
	textRect.w = 4 * 12 * 3;
	textRect.h = 30 * 3;
	SDL_RenderCopy(Game::renderer, left, NULL, &textRect);
	textRect.x = 50;
	textRect.y = 320;
	textRect.w = 4 * 12 * 3;
	textRect.h = 30 * 3;
	SDL_RenderCopy(Game::renderer, right, NULL, &textRect);
	textRect.x = 50;
	textRect.y = 420;
	textRect.w = 4 * 12 * 3;
	textRect.h = 30 * 3;
	SDL_RenderCopy(Game::renderer, jump, NULL, &textRect);
	textRect.x = 400;
	textRect.y = 220;
	textRect.w = 4 * 12 * 3;
	textRect.h = 30 * 3;
	SDL_RenderCopy(Game::renderer, down, NULL, &textRect);
	textRect.x = 400;
	textRect.y = 320;
	textRect.w = 4 * 12 * 3;
	textRect.h = 30 * 3;
	SDL_RenderCopy(Game::renderer, shoot, NULL, &textRect);
	textRect.x = 400;
	textRect.y = 420;
	textRect.w = 4 * 12 * 4;
	textRect.h = 30 * 3;
	SDL_RenderCopy(Game::renderer, interact, NULL, &textRect);
	textRect.x = 750;
	textRect.y = 220;
	textRect.w = 4 * 12 * 3;
	textRect.h = 30 * 3;
	SDL_RenderCopy(Game::renderer, useItem, NULL, &textRect);
	textRect.x = 750;
	textRect.y = 320;
	textRect.w = 4 * 12 * 4;
	textRect.h = 30 * 3;
	SDL_RenderCopy(Game::renderer, croutch, NULL, &textRect);
	textRect.x = 750;
	textRect.y = 420;
	textRect.w = 4 * 12 * 3;
	textRect.h = 30 * 3;
	SDL_RenderCopy(Game::renderer, dash, NULL, &textRect);

}
