#include "SoftPlatform.h"

#include "Player.h"

SoftPlatform::SoftPlatform(float x, float y, int init_tilesWidth) : GameObject("assets/StageObjects/SoftPlatform.png", x, y, 20, 3, 3) {

	width = init_tilesWidth * 60;

	tilesWidth = init_tilesWidth;

	collidable = true;
	solid = true;
	moveable = false;

}

SoftPlatform::~SoftPlatform() {}

void SoftPlatform::Update(LevelManager * game) {}

void SoftPlatform::RenderObject() {

	destRect.w = 60;

	for(int i = 0; i < tilesWidth; i++) {

		SDL_RenderCopy(Game::renderer, texture, &srcRect, &destRect);
		destRect.x += 60;

	}

}

bool SoftPlatform::OverrideCollision(GameObject * go) {

	if(dynamic_cast<Player *>(go) != nullptr && ((Player *)go)->DownPressed()) return true;
	return y + height < go->GetY() + go->GetHeight() || go->GetVY() < 0;

}
