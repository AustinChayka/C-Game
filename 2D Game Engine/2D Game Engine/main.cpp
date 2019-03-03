#include "SDL.h"

#include "Game.h"

Game * game = NULL;

int scale = 90;

int main(int argc, char * argv[]) {

	const float frameDelay = 1000.0f / 60.0f;

	Uint32 frameStart;
	int frameTime;

	game = new Game("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 16 * scale, 9 * scale, true);
		
	while(Game::running) {

		frameStart = SDL_GetTicks();

		game->HandleEvents();
		game->Update();
		game->Render();

		frameTime = SDL_GetTicks() - frameStart;

		//std::cout << frameTime << std::endl;

		if(frameDelay > frameTime) SDL_Delay((int)(frameDelay - frameTime));

	}

	game->Clean();
		
	return 0;

}