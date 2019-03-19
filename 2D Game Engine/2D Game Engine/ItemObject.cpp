#include "ItemObject.h"

#include "Heart.h"
#include "CursedCandle.h"
#include "MarkOfHunger.h"
#include "SpiralShell.h"
#include "HealthPotion.h"

ItemObject::ItemObject(float x, float y, int pool) : GameObject(nullptr, x, y, 24, 24) {

	collidable = false;
	solid = false;

	text = TextureManager::LoadText(Game::renderer, 24, {255, 255, 255}, "[E]");
	textRect.w = 20;
	textRect.h = 20;

	switch(pool) {

		case 0:
			switch(rand() % 3) {

				case 0:
					item = new Heart();
					texture = TextureManager::LoadTexture(Game::renderer, "assets/Items/Heart.png");
					break;

				case 1:
					item = new SpiralShell();
					texture = TextureManager::LoadTexture(Game::renderer, "assets/Items/SpiralShell.png");
					break;

				case 2:
					item = new HealthPotion();
					texture = TextureManager::LoadTexture(Game::renderer, "assets/Items/HealthPotion.png");
					break;

			}
			break;

		case 1:
			switch(rand() % 2) {

				case 0:
					item = new CursedCandle();
					texture = TextureManager::LoadTexture(Game::renderer, "assets/Items/CursedCandle.png");
					break;

				case 1:
					item = new MarkOfHunger();
					texture = TextureManager::LoadTexture(Game::renderer, "assets/Items/MarkOfHunger.png");
					break;

			}
			break;

	}

}

ItemObject::~ItemObject() {}

void ItemObject::Update(LevelManager * game) {

	if(damageDelay > 0) return;

	for(auto go : *game->GetObjects()) if(dynamic_cast<Player *>(go) != nullptr) if(CollidesWith(go)) {
		collided = true;
		if(Game::event.key.keysym.sym == SDLK_e && Game::event.type == SDL_KEYDOWN) {
			dead = true;
			((Player *)go)->AddItem(item, game);
		}
	} else collided = false;

	textRect.x = (int)((x - Game::camera->GetX()) * Game::camera->GetScale());
	textRect.y = (int)((y - 20 - Game::camera->GetY()) * Game::camera->GetScale());

}

void ItemObject::RenderObject() {

	GameObject::RenderObject();

	if(collided) SDL_RenderCopy(Game::renderer, text, NULL, &textRect);

}
