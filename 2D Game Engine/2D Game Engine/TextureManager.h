#ifndef TextureManager_h
#define TextureManager_h

#include "SDL.h"
#include "SDL_image.h"

class TextureManager {

public:

	static SDL_Texture * LoadTexture(SDL_Renderer * renderer, const char * filePath);

};

#endif