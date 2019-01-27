#include "SDL.h"

#include "Game.h"

Game * game = NULL;

int main(int argc, char * argv[]) {

	const float frameDelay = 1000.0f / 60.0f;

	Uint32 frameStart;
	int frameTime;

	game = new Game("OakEngine v0.2a", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);
		
	while(game->IsRunning()) {

		frameStart = SDL_GetTicks();

		game->HandleEvents();
		game->Update();
		game->Render();

		frameTime = SDL_GetTicks() - frameStart;

		if(frameDelay > frameTime) SDL_Delay((int)(frameDelay - frameTime));

	}

	game->Clean();
		
	return 0;

}