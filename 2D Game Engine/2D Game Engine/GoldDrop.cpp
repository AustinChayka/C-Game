#include "GoldDrop.h"

#include "Player.h"
#include "Projectile.h"

GoldDrop::GoldDrop(float x, float y, int init_value) : GameObject(nullptr, x, y, 
	5 + 2 * (init_value - 1), 5 + 2 * (init_value - 1)) {

	value = init_value;
	collidable = true;
	solid = true;
	moveable = true;

	grav = .4f;
	decceleration = 1.15f;

	renderLayer = 3;

}

GoldDrop::~GoldDrop() {}

void GoldDrop::Update(LevelManager * game) {}

void GoldDrop::RenderObject() {

	SDL_SetRenderDrawColor(Game::renderer, 255, 208, 0, 255);
	SDL_RenderFillRect(Game::renderer, &destRect);

}

void GoldDrop::OnCollision(GameObject * go, LevelManager * game) {

	if(dynamic_cast<Player *>(go) != nullptr) {
		((Player *)go)->AddGold(value);
		dead = true;
	}

}

bool GoldDrop::OverrideCollision(GameObject * go) {

	return go->IsMoveable() && dynamic_cast<GoldDrop *>(go) == nullptr && dynamic_cast<Projectile *>(go) == nullptr;

}
