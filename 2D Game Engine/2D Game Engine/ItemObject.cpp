#include "ItemObject.h"

#include "Heart.h"
#include "CursedCandle.h"
#include "MarkOfHunger.h"
#include "SpiralShell.h"
#include "HealthPotion.h"
#include "CharredSkull.h"
#include "PossesedNail.h"
#include "JarOfAir.h"
#include "RubberCement.h"
#include "Soul.h"
#include "FireTome_1.h"
#include "IceTome_1.h"
#include "PaperAirplane.h"
#include "DoubleVision.h"
#include "RapidFire.h"
#include "BloatedDoll.h"

std::vector<std::vector<int> *> * ItemObject::items = nullptr;

ItemObject::ItemObject(float x, float y, int pool) : GameObject(nullptr, x, y, 24, 24) {

	collidable = false;
	solid = false;

	text = TextureManager::LoadText(Game::renderer, 24, {255, 255, 255}, "[E]");
	textRect.w = 20;
	textRect.h = 20;

	renderLayer = 2;

	if(items == nullptr) {
		items = new std::vector<std::vector<int> *>;
		for(int i = 0; i < 3; i++) items->push_back(new std::vector<int>);
		for(int i = 0; i < 9; i++) items->at(0)->push_back(i);
		for(int i = 0; i < 5; i++) items->at(1)->push_back(i);
		for(int i = 0; i < 2; i++) items->at(2)->push_back(i);
	}
	
	GenerateItem(pool);

}

ItemObject::ItemObject(float x, float y, Item * i) : GameObject(nullptr, x, y, 24, 24) {

	collidable = false;
	solid = false;

	text = TextureManager::LoadText(Game::renderer, 24, {255, 255, 255}, "[E]");
	textRect.w = 20;
	textRect.h = 20;

	renderLayer = 2;

	item = i;
	texture = TextureManager::LoadTexture(Game::renderer, item->GetTexturePath());

}

ItemObject::~ItemObject() {

	SDL_DestroyTexture(text);
	if(item != nullptr) delete item;

}

void ItemObject::Update(LevelManager * game) {

	if(delay > 0) {
		delay--;
		return;
	}

	for(auto go : *game->GetObjects()) if(dynamic_cast<Player *>(go) != nullptr) if(CollidesWith(go)) {
		collided = true;
		if(Game::event.key.keysym.sym == SDLK_e && Game::event.type == SDL_KEYDOWN) {
			dead = true;
			((Player *)go)->AddItem(item, game);
			item = nullptr;
		}
	} else collided = false;

	textRect.x = (int)((x - Game::camera->GetX()) * Game::camera->GetScale());
	textRect.y = (int)((y - 20 - Game::camera->GetY()) * Game::camera->GetScale());

}

void ItemObject::RenderObject() {

	GameObject::RenderObject();

	if(collided) SDL_RenderCopy(Game::renderer, text, NULL, &textRect);

}

void ItemObject::GenerateItem(int pool) {

	int n = items->at(pool)->size() > 0 ? rand() % items->at(pool)->size() : 0,
		i = items->at(pool)->size() > 0 ? items->at(pool)->at(n) : 0;

	switch(pool) {

		case 0:
			switch(i) {

				case 0:
					item = new Heart();
					break;

				case 1:
					item = new SpiralShell();
					break;

				case 2:
					item = new HealthPotion();
					break;

				case 3:
					item = new PossesedNail();
					break;

				case 4:
					item = new JarOfAir();
					break;

				case 5:
					item = new RubberCement();
					break;

				case 6:
					item = new PaperAirplane();
					break;

				case 7:
					item = new DoubleVision();
					break;

				case 8:
					item = new RapidFire();
					break;

			}
			break;

		case 1:
			switch(i) {

				case 0:
					item = new Soul();
					break;

				case 1:
					item = new CursedCandle();
					break;

				case 2:
					item = new MarkOfHunger();
					break;

				case 3:
					item = new CharredSkull();
					break;

				case 4:
					item = new BloatedDoll();
					break;

			}
			break;

		case 2:
			switch(i) {

				case 0:
					item = new FireTome_1();
					break;

				case 1:
					item = new IceTome_1();
					break;

			}
			break;

	}

	texture = TextureManager::LoadTexture(Game::renderer, item->GetTexturePath());

	if(items->at(pool)->size() > 0) items->at(pool)->erase(items->at(pool)->begin() + n);

}
