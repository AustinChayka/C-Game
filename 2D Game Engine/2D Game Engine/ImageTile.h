#ifndef ImageTile_h
#define ImageTile_h

#include "SDL.h"
#include "TextureManager.h"
#include "Game.h"

class ImageTile {

public:

	ImageTile(const char * filepath, float init_x, float init_y, int img_width, int img_height, float tileX, float tileY,
		float scale, int init_layer);

	ImageTile(const char * filepath, float init_x, float init_y, int img_width, int img_height, float tileX, float tileY,
		float scale, int init_layer, int init_tiles, float init_tileSpeed);

	~ImageTile();

	void Update();
	void Render();

	SDL_Texture * GetTexture();

	int GetLayer();

private:

	SDL_Texture * texture;

	SDL_Rect srcRect, destRect;

	float x, y, tileX, tileY, tileSpeed;
	int width, height, layer, tiles = -1;

};

#endif