#include "HealthPotion.h"

#include "RegenStatus.h"
#include "Soul.h"

HealthPotion::HealthPotion() : UseableItem("assets/Items/HealthPotion.png", "Health Potion", "probably not poisoned") {

	synergy = typeid(Soul).name();

	destRect.w = 20;
	destRect.h = 5;
	destRect.y = Game::height - 8;

}

HealthPotion::~HealthPotion() {}

bool HealthPotion::OnUse(LevelManager * game, Player * p) {

	if(p->GetMaxHealth() == p->GetHealth()) return false;

	int power = rand() % (int)(p->GetMaxHealth() * .25f) + (int)(p->GetMaxHealth() * .5f), r = rand() % power;

	p->Heal(r);
	p->AddStatus(new RegenStatus(power - r));

	if(charges < maxCharges) {
		charges++;
		return false;
	}
	charges = 0;
	return true;

}

void HealthPotion::Update(LevelManager * game, Player * p) {

	UseableItem::Update(game, p);

	if(synergyActive) maxCharges = 2;
	else maxCharges = 1;

}

void HealthPotion::Render() {

	if(!synergyActive) return;

	SDL_SetRenderDrawColor(Game::renderer, 0, 100, 0, 255);
	destRect.x = 45;
	SDL_RenderFillRect(Game::renderer, &destRect);
	if(charges == 2) SDL_SetRenderDrawColor(Game::renderer, 150, 150, 150, 255);
	destRect.x = 72;
	SDL_RenderFillRect(Game::renderer, &destRect);

}
