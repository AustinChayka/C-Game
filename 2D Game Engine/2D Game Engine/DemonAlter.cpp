#include "DemonAlter.h"

#include "Player.h"
#include "ItemObject.h"

DemonAlter::DemonAlter(float x, float y) : GameObject("assets/StageObjects/DemonAlter.png", x, y, 40, 50, 3) {

	collidable = true;
	moveable = false;
	solid = false;

	text = TextureManager::LoadText(Game::renderer, 24, {255, 0, 0}, "[E] Strike a deal.");

	destRect.w = 30 * 10;
	destRect.h = 30;

}

DemonAlter::~DemonAlter() {

	SDL_DestroyTexture(text);

}

void DemonAlter::Update(LevelManager * game) {

	if(!active) {
		tileX += .08f;
		if(tileX > 4) tileX = 0;
		return;
	}

	for (auto go : *(game->GetObjects())) if(dynamic_cast<Player *>(go) != nullptr) if(CollidesWith(go)) {
		if(go->GetMaxHealth() > 4) {
			collided = true;
			if(Game::event.key.keysym.sym == SDLK_e && Game::event.type == SDL_KEYDOWN) {
				go->SetMaxHealth(go->GetMaxHealth() - 4);
				active = false;
				collided = false;
				tileY = 1;
				game->AddObject(new ItemObject(GetXCenter() - 12, y + 50 * 3 - 24, 1));
			}
		}
	} else collided = false;

	destRect.x = (int)((GetXCenter() - Game::camera->GetX() - 150) * Game::camera->GetScale());
	destRect.y = (int)((y - Game::camera->GetY() - 40) * Game::camera->GetScale());
	
}

void DemonAlter::RenderObject() {

	GameObject::RenderObject();

	if(collided) SDL_RenderCopy(Game::renderer, text, NULL, &destRect);

}
