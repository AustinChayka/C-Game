#include "Block.h"


Block::Block(float x, float y, int init_tilesWidth, int init_tilesHeight) : 
	GameObject("assets/Block.png", x, y, 20 * tilesWidth, 20 * tilesHeight, 3) {

	tilesWidth = init_tilesWidth;
	tilesHeight = init_tilesHeight;

	width = 20 * tilesWidth * scale;
	height = 20 * tilesHeight * scale;

	collidable = true;
	moveable = false;

}

Block::~Block() {}

void Block::Update(LevelManager * game) {}

void Block::RenderObject() {
	
	srcRect.w = 20;
	srcRect.h = 20;
	destRect.w = 20 * scale;
	destRect.h = 20 * scale;
	
	for(int j = 0; j < tilesHeight; j++) {
		for(int i = 0; i < tilesWidth; i++) {

			destRect.x += 20 * i * scale;
			
			SDL_RenderCopy(Game::renderer, texture, &srcRect, &destRect);

			destRect.x -= 20 * i * scale;

		}

		destRect.y += 20 * scale;

	}

}