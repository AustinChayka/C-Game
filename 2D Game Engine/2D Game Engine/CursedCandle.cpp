#include "CursedCandle.h"

#include "CursedFireball.h"

CursedCandle::CursedCandle() : Item("assets/Items/CursedCandle.png", "Cursed Candle", "now you see...") {

	spiritTexture = TextureManager::LoadTexture(Game::renderer, "assets/Enemies/Spirit.png");
	destRect0.w = destRect1.w = 13 * 2;
	destRect0.h = destRect1.h = 29 * 2;
	srcRect.w = 13;
	srcRect.h = 29;

	renderLayer = 3;
		
}

void CursedCandle::Update(LevelManager * game, Player * p) {

	if(target == nullptr) for(auto go : *game->GetObjects()) if(go != p && go->IsDamagable() && p->DistanceToSquared(go) < 700 * 700 &&
		dynamic_cast<Enemy *>(go) != nullptr) {
		target = go;
		break;
	} else if(!target) target = nullptr;

	if(fireDelay <= 0 && target != nullptr) {
		if(active == 0) {
			game->AddObject(new CursedFireball(p->GetX() - 13, p->GetY() - 29,
				(target->GetXCenter() - (p->GetX() - 13)) / 20,
				(target->GetYCenter() - (p->GetY() - 29)) / 20, 0, 0, p));
			active = 1;
		} else {
			game->AddObject(new CursedFireball(p->GetX() + p->GetWidth() + 13, p->GetY() - 29, 
				(target->GetXCenter() - (p->GetX() + p->GetWidth() + 13)) / 20,
				(target->GetYCenter() - (p->GetY() - 29)) / 20, 0, 0, p));
			active = 0;
		}
		fireDelay = 180;
	} else fireDelay--;

	tileX += .1f;

	if(tileX > 6) tileX = 0;
	srcRect.x = (int)tileX * 13;

	destRect0.x = (int)((p->GetX() - 26 - Game::camera->GetX()) * Game::camera->GetScale());
	destRect0.y = (int)((p->GetY() - 58 - Game::camera->GetY()) * Game::camera->GetScale());
	destRect1.x = (int)((p->GetX() + p->GetWidth() - Game::camera->GetX()) * Game::camera->GetScale());
	destRect1.y = (int)((p->GetY() - 58 - Game::camera->GetY()) * Game::camera->GetScale());

}

void CursedCandle::Render() {

	SDL_RenderCopy(Game::renderer, spiritTexture, &srcRect, &destRect0);
	SDL_RenderCopy(Game::renderer, spiritTexture, &srcRect, &destRect1);

}


CursedCandle::~CursedCandle() {

	SDL_DestroyTexture(spiritTexture);

}
