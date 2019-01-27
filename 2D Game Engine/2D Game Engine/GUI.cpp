#include "GUI.h"

GUI::GUI(GameObject * p) {

	player = p;

}

GUI::~GUI() {}

void GUI::Update() {}

void GUI::Render() {

	for(int i = 0; i < 10; i++) {

		for(int y = 0; y < 25; y++) for(int x = 0; x < 10; x++) {

			SDL_SetRenderDrawColor(Game::renderer, 255, 0, 0, 150);
			SDL_RenderDrawPoint(Game::renderer, x + 15 + i * 15, y + 15);

		}

	}

}
