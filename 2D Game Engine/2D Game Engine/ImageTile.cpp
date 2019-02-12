#include "ImageTile.h"

ImageTile::ImageTile(const char * filepath, float init_x, float init_y, int img_width, int img_height, 
	float init_tileX, float init_tileY, float scale, int init_layer) {

	texture = TextureManager::LoadTexture(Game::renderer, filepath);

	x = init_x;
	y = init_y;
	width = img_width * scale;
	height = img_height * scale;
	tileX = init_tileX;
	tileY = init_tileY;

	srcRect.x = tileX * (int)img_width;
	srcRect.y = tileY * (int)img_height;
	srcRect.w = (int)img_width;
	srcRect.h = (int)img_height;

	layer = init_layer;

}

ImageTile::~ImageTile() {

	SDL_DestroyTexture(texture);

}

void ImageTile::Update() {

	destRect.x = (int)((x - Game::camera->GetX()) * Game::camera->GetScale());
	destRect.y = (int)((y - Game::camera->GetY()) * Game::camera->GetScale());
	destRect.w = (int)(width * Game::camera->GetScale());
	destRect.h = (int)(height * Game::camera->GetScale());

}

void ImageTile::Render() {

	SDL_RenderCopy(Game::renderer, texture, &srcRect, &destRect);

}

SDL_Texture * ImageTile::GetTexture() {

	return texture;

}

int ImageTile::GetLayer() {

	return layer;

}
