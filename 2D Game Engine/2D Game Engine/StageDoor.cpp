#include "StageDoor.h"

#include "Player.h"

StageDoor::StageDoor(float x, float y, bool init_exit) : GameObject("assets/StageDoor.png", x, y, 28, 48, 3) {

	solid = false;
	moveable = false;
	
	text = TextureManager::LoadText(Game::renderer, 24, {255, 255, 255, 200}, "[E]");
	textRect.w = 20;
	textRect.h = 20;

	exit = init_exit;
	if(exit) tileX = 1;

}

StageDoor::~StageDoor() {

	SDL_DestroyTexture(text);

}

void StageDoor::Update(LevelManager * game) {

	if(!exit) return;

	for(auto go : *game->GetObjects()) if(dynamic_cast<Player *>(go) != nullptr) if(CollidesWith(go)) {
		collided = true;
		if(Game::event.key.keysym.sym == SDLK_e && Game::event.type == SDL_KEYDOWN) {
			game->NextLevel();
			return;
		}
	} else collided = false;

	textRect.x = (int)((x - Game::camera->GetX()) * Game::camera->GetScale());
	textRect.y = (int)((y - Game::camera->GetY()) * Game::camera->GetScale());

}

void StageDoor::RenderObject() {

	GameObject::RenderObject();

	if(collided) SDL_RenderCopy(Game::renderer, text, NULL, &textRect);

}
