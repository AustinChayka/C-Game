#include "SDL.h"

#include "Game.h"

Game * game = NULL;

int scale = 80;

int main(int argc, char * argv[]) {

	const float frameDelay = 1000.0f / 60.0f;

	Uint32 frameStart;
	int frameTime;

	game = new Game("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 16 * scale, 9 * scale, true);
		
	try {

		while(Game::running) {

			frameStart = SDL_GetTicks();

			game->HandleEvents();
			game->Update();
			game->Render();


			frameTime = SDL_GetTicks() - frameStart;

			//std::cout << frameTime << std::endl;

			if(frameDelay > frameTime) SDL_Delay((int)(frameDelay - frameTime));

		}
	
	} catch(const std::exception &e) {

		SDL_SetWindowFullscreen(game->GetWindow(), 0);

	}

	game->Clean();
		
	return 0;

}