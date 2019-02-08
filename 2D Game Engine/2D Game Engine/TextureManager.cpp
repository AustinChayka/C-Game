#include "TextureManager.h"

SDL_Texture * TextureManager::LoadTexture(SDL_Renderer * renderer, const char * filePath) {
	
	SDL_Surface * surface = IMG_Load(filePath);
	SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);

	return texture;

}

SDL_Texture * TextureManager::LoadText(SDL_Renderer * renderer, int fontSize, SDL_Color fontColor, const char * text) {

	TTF_Font * font = TTF_OpenFont("8514fix.fon", fontSize);
	SDL_Surface * surface = TTF_RenderText_Blended(font, text, fontColor);
	SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
	TTF_CloseFont(font);

	return texture;

}
