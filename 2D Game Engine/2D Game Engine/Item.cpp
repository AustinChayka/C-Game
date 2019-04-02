#include "Item.h"

Item::Item(const char * iconPath, const char * name, const char * itemFlavor) {

	icon = TextureManager::LoadTexture(Game::renderer, iconPath);

	nameText = TextureManager::LoadText(Game::renderer, 24, {255, 255, 255}, name);

	flavorText = TextureManager::LoadText(Game::renderer, 12, {255, 255, 255}, itemFlavor);

	nameLength = strlen(name);
	flavorTextLength = strlen(itemFlavor);
	
}

void Item::Update(LevelManager * game, Player * p) {}

void Item::OnPickup(LevelManager * game, Player * p) {}

void Item::OnDamageTaken(LevelManager * game, GameObject * go, Player * p) {}

void Item::OnShotFired(LevelManager * game, Player * p, Projectile *& proj) {}

void Item::OnDamageDelt(LevelManager * game, Player * p, GameObject * go) {}

void Item::UpdateProjectile(LevelManager * game, Player * p, Projectile * proj) {}

void Item::OnKill(LevelManager * game, Player * p, GameObject * go) {}

void Item::Render() {}

SDL_Texture * Item::GetTexture() {

	return icon;

}

SDL_Texture * Item::GetNameText() {

	return nameText;

}

SDL_Texture * Item::GetFlavorText() {

	return flavorText;

}

int Item::GetNameLength() {

	return nameLength;

}

int Item::GetFlavorTextLength() {

	return flavorTextLength;

}

Item::~Item() {

	SDL_DestroyTexture(icon);

}
