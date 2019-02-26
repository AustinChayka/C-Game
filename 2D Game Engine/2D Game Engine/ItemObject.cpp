#include "ItemObject.h"

#include "Heart.h"

ItemObject::ItemObject(float x, float y, int type) : GameObject(nullptr, x, y, 24, 24) {

	collidable = false;
	solid = false;

	text = TextureManager::LoadText(Game::renderer, 24, {255, 255, 255}, "[E]");
	textRect.w = 20;
	textRect.h = 20;

	switch(type) {

		case 0:
			texture = TextureManager::LoadTexture(Game::renderer, "assets/Items/Heart.png");
			item = new Heart(x, y);

	}

}

ItemObject::~ItemObject() {}

void ItemObject::Update(LevelManager * game) {

	for(auto go : *game->GetObjects()) if(dynamic_cast<Player *>(go) != nullptr) if(CollidesWith(go)) {
		collided = true;
		if(Game::event.key.keysym.sym == SDLK_e && Game::event.type == SDL_KEYDOWN) {
			dead = true;
			((Player *)go)->AddItem(item, game);
		}
	} else collided = false;

	textRect.x = (int)((x - Game::camera->GetX()) * Game::camera->GetScale());
	textRect.y = (int)((y - Game::camera->GetY()) * Game::camera->GetScale());

}

void ItemObject::RenderObject() {

	GameObject::RenderObject();

	if(collided) SDL_RenderCopy(Game::renderer, text, NULL, &textRect);

}
