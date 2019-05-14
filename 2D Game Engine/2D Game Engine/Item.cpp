#include "Item.h"

Item::Item(const char * iconPath, const char * name, const char * itemFlavor) {

	icon = TextureManager::LoadTexture(Game::renderer, iconPath);

	nameText = TextureManager::LoadText(Game::renderer, 24, {255, 255, 255}, name);

	flavorText = TextureManager::LoadText(Game::renderer, 12, {255, 255, 255}, itemFlavor);

	nameLength = strlen(name);
	flavorTextLength = strlen(itemFlavor);
	texturePath = iconPath;
	
}

void Item::Update(LevelManager * game, Player * p) {

	if(synergy == nullptr) return;
	synergyActive = false;
	for(auto i : *p->GetItems()) if(typeid(*i).name() == synergy) {
		synergyActive = true;
	}

}

void Item::OnPickup(LevelManager * game, Player * p) {

	if(synergy == nullptr) return;
	for(auto i : *p->GetItems()) if(typeid(*i).name() == synergy) {
		synergyActive = true;
	}
	
}

void Item::OnDamageTaken(LevelManager * game, GameObject * go, Player * p) {}

int Item::OverrideDamageTotal(int damage, GameObject * go, Player * p) {

	return 0;

}

bool Item::OverrideDefaultProjectile(Player * p, Projectile *& proj) {

	return false;

}

void Item::OnShotFired(LevelManager * game, Player * p, Projectile *& proj) {}

void Item::OnDamageDelt(LevelManager * game, Player * p, GameObject * go, bool crit) {}

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

int Item::GetLayer() {

	return renderLayer;

}

const char * Item::GetTexturePath() {

	return texturePath;

}

bool Item::IsSynergyActive() {

	return synergyActive;

}

Item::~Item() {

	SDL_DestroyTexture(icon);

}
