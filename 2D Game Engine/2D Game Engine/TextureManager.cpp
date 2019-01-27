#include "TextureManager.h"

SDL_Texture * TextureManager::LoadTexture(SDL_Renderer * renderer, const char * filePath) {
	
	SDL_Surface * surface = IMG_Load(filePath);
	SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);

	return texture;

}
