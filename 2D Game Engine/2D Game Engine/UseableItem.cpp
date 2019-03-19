#include "UseableItem.h"

UseableItem::UseableItem(const char * path, const char * name, const char * flavor) : Item(path, name, flavor) {}

UseableItem::~UseableItem() {}

void UseableItem::Update(LevelManager * game, Player * p) {

	if(recharge > 0) recharge--;
	else {
		if(Game::event.key.keysym.sym == SDLK_q && Game::event.type == SDL_KEYDOWN) {
			if(OnUse(game, p)) recharge = rechargeTime;
		}
	}

}

int UseableItem::GetRecharge() {

	return recharge;

}

int UseableItem::GetChargeTime() {

	return rechargeTime;

}
