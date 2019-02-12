#ifndef ImageTile_h
#define ImageTile_h

#include "SDL.h"
#include "TextureManager.h"
#include "Game.h"

class ImageTile {

public:

	ImageTile(const char * filepath, float init_x, float init_y, int img_width, int img_height, float tileX, float tileY,
		float scale, int init_layer);

	~ImageTile();

	void Update();
	void Render();

	SDL_Texture * GetTexture();

	int GetLayer();

private:

	SDL_Texture * texture;

	SDL_Rect srcRect, destRect;

	float x, y, tileX, tileY;
	int width, height, layer;

};

#endif