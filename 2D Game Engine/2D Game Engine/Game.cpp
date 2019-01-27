#include "Game.h"

SDL_Renderer * Game::renderer = nullptr;
SDL_Event Game::event;
StateManager * stateManager = nullptr;

Camera * Game::camera = nullptr;

int Game::width;
int Game::height;

GUI * Game::gui = nullptr;

Game::Game(const char * title, int xPos, int yPos, int init_width, int init_height, bool fullscreen) {

	width = init_width;
	height = init_height;

	int flags = 0;
	if(fullscreen) flags = SDL_WINDOW_FULLSCREEN;

	if(SDL_Init(SDL_INIT_EVERYTHING) == 0) {

		std::cout << "SDL subsystems initialized." << std::endl;

		window = SDL_CreateWindow(title, xPos, yPos, width, height, flags);
		if(window) {

			std::cout << "Window created." << std::endl;

			renderer = SDL_CreateRenderer(window, -1, 0);
			if(renderer) {

				std::cout << "Renderer created." << std::endl;

				SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
				SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

				running = true;

			} else std::cout << "Failed to create renderer. Error: " << SDL_GetError() << std::endl;

		} else std::cout << "Failed to create window. Error: " << SDL_GetError() << std::endl;

	} else  std::cout << "SDL failed to initialize. Error: " << SDL_GetError() << std::endl;
	
	camera = new Camera(0, 0, width, height);

	stateManager = new StateManager();

	gui = new GUI(LevelManager::player);
	
}

Game::~Game() {



}

void Game::HandleEvents() {

	SDL_PollEvent(&event);

	switch(event.type) {

		case SDL_QUIT:
			running = false;
			break;

		default:
			break;

	}

}

void Game::Update() {

	stateManager->Update();

	camera->Update();

}

void Game::Render() {

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	stateManager->Render();

	SDL_RenderPresent(renderer);

}

void Game::Clean() {

	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();

	std::cout << "Game systems cleaned." << std::endl;

}

bool Game::IsRunning() {

	return running;

}
