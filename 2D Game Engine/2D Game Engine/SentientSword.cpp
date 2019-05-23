#include "SentientSword.h"

SentientSword::SentientSword() : Item("assets/Items/SentientSword.h", "Sentient Sword", "it whispers...") {

	texture = TextureManager::LoadTexture(Game::renderer, "assets/Other/SentientSword.png");
	srcRect.w = 50;
	srcRect.h = 15;
	destRect.w = 100;
	destRect.h = 30;

	renderLayer = 3;

}

SentientSword::~SentientSword() {}

void SentientSword::Update(LevelManager * game, Player * p) {

	Item::Update(game, p);

	UpdateSword(game, p);

	if(attack > 0) attack--;
	if(attackDelay > 0) attackDelay--;
	if(damageDelay > 0) damageDelay--;
	else {

		for(auto go : *game->GetObjects()) {

			if(go != p && go->IsDamagable() && x + destRect.w > go->GetX() && x < go->GetX() + go->GetWidth() &&
				y + destRect.h > go->GetY() && y < go->GetY() + go->GetHeight()) {
				go->DealDamage(1, game);
				damageDelay = 20;
			}

		}

	}

	x += vX;
	y += vY;
	
	if(vX > 0) srcRect.y = 0;
	else if(vX < 0) srcRect.y = 15;
	destRect.x = (int)((x - Game::camera->GetX()) * Game::camera->GetScale());
	destRect.y = (int)((y - 20 - Game::camera->GetY()) * Game::camera->GetScale());

}

void SentientSword::OnPickup(LevelManager * game, Player * p) {

	Item::OnPickup(game, p);

	x = p->GetX();
	y = p->GetY();

}

void SentientSword::Render() {

	SDL_RenderCopy(Game::renderer, texture, &srcRect, &destRect);

}

float SentientSword::GetXCenter() {

	return x + destRect.w / 2;

}

float SentientSword::GetYCenter() {

	return y + destRect.h / 2;

}

void SentientSword::UpdateSword(LevelManager * game, Player * p) {

	if(attack > 0) return;

	if(target == nullptr) for(auto go : *game->GetObjects()) if(go != p && dynamic_cast<Enemy *>(go) != nullptr &&
		p->DistanceToSquared(go) <= 700 * 700) {
		target = go;
		break;
	}

	if(DistanceToSquared(p) > 1000 * 1000 || !target) target = nullptr;

	if(target == nullptr) {
		if(DistanceToSquared(p) > 100 * 100) vX = (p->GetXCenter() - GetXCenter()) / 30;
		else vX = 0;
		if(abs(GetYCenter() - p->GetYCenter()) > 10) vY = (p->GetYCenter() - GetYCenter()) / 30;
		else vY = 0;
		return;
	}

	if(!target || target->IsDead()) {
		target = nullptr;
		return;
	}

	if(DistanceToSquared(target) > 150 * 150) vX = (target->GetXCenter() - GetXCenter()) / 50;
	else vX = 0;
	if(abs(GetYCenter() - target->GetYCenter()) > 5) vY = (target->GetYCenter() - GetYCenter()) / 50;
	else vY = 0;

	if(DistanceToSquared(target) <= 250 * 250 && abs(GetYCenter() - target->GetYCenter()) <= 20) {
		vX = (x < target->GetX() ? 20 : -20);
		attack = 30;
	}

}

float SentientSword::DistanceToSquared(GameObject * go) {

	return pow(x - go->GetX(), 2) + pow(y - go->GetY(), 2);

}
