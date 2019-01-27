#include "Platform.h"

#include "SDL.h"

Platform::Platform(float x, float y, int segments_width) : GameObject("assets/Platform.png", x, y, 16, 8, 3) {

	width = 16 * segments_width * scale;
	segments = segments_width;

	collidable = true;
	moveable = false;

}

Platform::~Platform() {}

void Platform::RenderObject() {

	destRect.w = 16 * scale;

	for(int i = 0; i < segments; i++) {

		if(i == 0) srcRect.x = 0;
		else if(i == segments - 1) srcRect.x = 32;
		else srcRect.x = 16;
		
		srcRect.y = 0;
		SDL_RenderCopy(Game::renderer, texture, &srcRect, &destRect);
		srcRect.y = 8;
		destRect.y += 8 * scale;
		SDL_RenderCopy(Game::renderer, texture, &srcRect, &destRect);
		destRect.y -= 8 * scale;
		destRect.x += 16 * scale;

	}
	
	
}

void Platform::Update(LevelManager * game) {}
