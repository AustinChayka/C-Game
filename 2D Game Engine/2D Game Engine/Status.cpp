#include "Status.h"

Status::Status(const char * iconPath, int init_increment) {

	icon = TextureManager::LoadTexture(Game::renderer, iconPath);

	increment = init_increment;

	time = lifeTime;

	srcRect.w = 10;
	srcRect.h = 10;

}

Status::~Status() {

	SDL_DestroyTexture(icon);

}

void Status::Update(GameObject * go, LevelManager * game) {

	if(time > 0) time--;
	else {
		if(increment > 0) increment--;
		else {
			OnEnd(go, game);
		}
		time = lifeTime;
		OnIncrement(go, game);
	}

	destRect.x = (int)((go->GetXCenter() - 15 - Game::camera->GetX()) * Game::camera->GetScale());
	destRect.y = (int)((go->GetY() - 40 - Game::camera->GetY()) * Game::camera->GetScale());
	destRect.w = (int)(30 * Game::camera->GetScale());
	destRect.h = (int)(30 * Game::camera->GetScale());

}

void Status::Render(int y) {

	destRect.y -= y * 30;
	destRect.x -= (increment / 2.0f) * 15;
	for(int i = 0; i < increment; i++) {
		destRect.x += 15;
		SDL_RenderCopy(Game::renderer, icon, &srcRect, &destRect);
	}

}

int Status::GetIncrement() {

	return increment;

}

void Status::SetIncrement(int i) {

	if(i < maxStacks)
		increment = i;
	else increment = maxStacks;

}

bool Status::IsActive() {

	return increment > 0;

}
