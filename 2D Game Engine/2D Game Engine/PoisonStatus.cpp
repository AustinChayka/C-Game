#include "PoisonStatus.h"

PoisonStatus::PoisonStatus(int i) : Status("assets/Icons/PoisonIcon.png", i) {

	maxStacks = 15;
	lifeTime = 60 * 5;

}

PoisonStatus::~PoisonStatus() {}

void PoisonStatus::Render(int y) {

	destRect.y -= y * 30;
	destRect.x -= (maxStacks / 2.0f) * 15;
	for(int i = 0; i < maxStacks; i++) {
		if(i < increment) srcRect.x = 0;
		else srcRect.x = 10;
		destRect.x += 15;
		SDL_RenderCopy(Game::renderer, icon, &srcRect, &destRect);
	}

}

void PoisonStatus::OnApply(GameObject * go) {

}

void PoisonStatus::OnIncrement(GameObject * go, LevelManager * game) {}

void PoisonStatus::OnEnd(GameObject * go, LevelManager * game) {

	SDL_SetTextureColorMod(go->GetTexture(), 255, 255, 255);

}

void PoisonStatus::OnUpdate(GameObject * go, LevelManager * game) {
	
	if(increment == maxStacks) active = true;

	if(active) {
		if(delay > 0) delay--;
		else {
			if(increment % 3 == 0) go->DealDamage(1, game);
			delay = 5;
			increment--;
		}
	}
	SDL_SetTextureColorMod(go->GetTexture(), 255 - increment * maxStacks, 255, 255 - increment * maxStacks);

}
