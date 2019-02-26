#include "Item.h"

Item::Item(const char * iconPath, const char * name) {

	icon = TextureManager::LoadTexture(Game::renderer, iconPath);

	nameText = TextureManager::LoadText(Game::renderer, 24, {255, 255, 255}, name);

}

void Item::Update(LevelManager * game, Player * p) {}

void Item::OnPickup(LevelManager * game, Player * p) {}

void Item::OnDamageTaken(LevelManager * game, GameObject * go, Player * p) {}

void Item::OnShotFired(LevelManager * game, Player * p) {}

SDL_Texture * Item::GetTexture() {

	return icon;

}

Item::~Item() {}
