#include "UseableItem.h"

UseableItem::UseableItem(const char * path, const char * name, const char * flavor) : Item(path, name, flavor) {}

UseableItem::~UseableItem() {}

void UseableItem::Update(LevelManager * game, Player * p) {

	Item::Update(game, p);

	if(recharge > 0) recharge--;
	else {
		if(Game::inputManager->IsPressed(InputManager::useItem)) {
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
