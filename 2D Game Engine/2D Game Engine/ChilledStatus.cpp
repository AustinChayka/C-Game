#include "ChilledStatus.h"

#include "SDL.h"

ChilledStatus::ChilledStatus(int i) : Status("assets/Icons/ChilledIcon.png", i) {

	maxStacks = 10;

	lifeTime = 120;

}

ChilledStatus::~ChilledStatus() {}

void ChilledStatus::OnApply(GameObject * go) {
	
}

void ChilledStatus::OnIncrement(GameObject * go, LevelManager * game) {}

void ChilledStatus::OnEnd(GameObject * go, LevelManager * game) {

	SDL_SetTextureColorMod(go->GetTexture(), 255, 255, 255);

}

void ChilledStatus::OnUpdate(GameObject * go, LevelManager * game) {

	go->SetVX(go->GetVX() / (increment / 10.0f + 1));
	if(go->GetVY() < 0) go->SetVY(go->GetVY() / (increment / 10.0f + 1));
	SDL_SetTextureColorMod(go->GetTexture(), 255 - increment * maxStacks, 255 - increment * maxStacks, 255);

}
