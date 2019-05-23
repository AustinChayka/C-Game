#include "SpiralShell.h"

SpiralShell::SpiralShell() : Item("assets/Items/SpiralShell.png", "Spiral Shell", "Protection") {

	srcRrect.w = 12;
	srcRrect.h = 24;

	destRect.w = 12;
	destRect.h = 24;

	renderLayer = 3;

}

SpiralShell::~SpiralShell() {}

int SpiralShell::OverrideDamageTotal(int damage, GameObject * go, Player * p) {

	if(health == 0) return 0;

	delay = 600;

	health -= damage;

	if(health >= 0) return damage;
	else return damage + health;

}

void SpiralShell::Update(LevelManager * game, Player * p) {

	Item::Update(game, p);

	if(health < 0) health = 0;

	if(delay > 0) delay--;
	else if(health < 8) {
		health++;
		delay = 30;
	}

}

void SpiralShell::Render() {

	int offX = 15;
	for(int i = 0; i < health; i++) {
		destRect.x = offX + 12 * i;
		destRect.y = 30 + 30 * (int)ceil(LevelManager::player->GetMaxHealth() / 20.0f);;
		if(i % 2 == 1) {
			srcRrect.x = 12;
			offX += 5;
		}
		else srcRrect.x = 0;
		SDL_SetTextureAlphaMod(icon, 255);
		SDL_RenderCopy(Game::renderer, icon, &srcRrect, &destRect);
	}

}
