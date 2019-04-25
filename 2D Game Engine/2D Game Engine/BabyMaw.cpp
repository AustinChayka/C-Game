#include "BabyMaw.h"

#include "MawProjectile.h"
#include "Enemy.h"

BabyMaw::BabyMaw() : Item("assets/Items/Bait.png", "Maw Bait", "baby abomination") {

	texture = TextureManager::LoadTexture(Game::renderer, "assets/Enemies/BabyMaw.png");
	srcRect.w = NULL;
	srcRect.h = NULL;

	width = 39;
	height = 39;

}

BabyMaw::~BabyMaw() {}

void BabyMaw::OnPickup(LevelManager * game, Player * p) {
	
	x = p->GetX();
	y = p->GetY();

}

void BabyMaw::UpdateMaw(LevelManager * game, Player * p) {

	if(target == nullptr) for(auto go : *game->GetObjects()) if(go != p && dynamic_cast<Enemy *>(go) != nullptr &&
		p->DistanceToSquared(go) <= 500 * 500) {
		target = go;
		break;
	} else if(!target) target = nullptr;

	if(DistanceToSquared(p) > 850 * 850 || !target) target = nullptr;

	if(target == nullptr) {
		if(DistanceToSquared(p) > 100 * 100) vX = (p->GetXCenter() - GetXCenter()) / 75;
		else vX = 0;
		if(abs(GetYCenter() - p->GetY()) > 10) vY = (p->GetYCenter() - GetYCenter()) / 75;
		else vY = 0;
		return;
	}

	if(DistanceToSquared(target) > 300 * 300) vX = (target->GetXCenter() - GetXCenter()) / 100;
	else vX = 0;
	if(abs(GetYCenter() - target->GetYCenter()) > 100) vY = (target->GetYCenter() - GetYCenter()) / 100;
	else vY = 0;

	if(chargeDelay > 0) chargeDelay--;
	else {
		if(shotDelay > 0) shotDelay--;
		else if(shots != 0){
			shots--;
			shotDelay = 10;
			game->AddObject(new MawProjectile(GetXCenter(), GetYCenter(), (target->GetXCenter() - GetXCenter()) / 20,
				(target->GetYCenter() - GetYCenter()) / 20, 0, 0, p));
		} else {
			chargeDelay = 100;
			shots = 3;
		}
	}
	
}

void BabyMaw::Update(LevelManager * game, Player * p) {

	UpdateMaw(game, p);

	x += vX;
	y += vY;

	srcRect.x = (int)tileX * srcRect.w;

	destRect.x = (int)((x - Game::camera->GetX()) * Game::camera->GetScale());
	destRect.y = (int)((y - Game::camera->GetY()) * Game::camera->GetScale());
	destRect.w = (int)(width * Game::camera->GetScale());
	destRect.h = (int)(height * Game::camera->GetScale());

}

void BabyMaw::Render() {

	//SDL_RenderCopy(Game::renderer, texture, &srcRect, &destRect);
	SDL_SetRenderDrawColor(Game::renderer, 80, 150, 150, 255);
	SDL_RenderFillRect(Game::renderer, &destRect);

}

float BabyMaw::GetXCenter() {

	return x + width / 2;

}

float BabyMaw::GetYCenter() {

	return y + height / 2;

}

float BabyMaw::DistanceToSquared(GameObject * go) {

	return pow(x - go->GetX(), 2) + pow(y - go->GetY(), 2);

}