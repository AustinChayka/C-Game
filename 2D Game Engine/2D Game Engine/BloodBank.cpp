#include "BloodBank.h"

#include "Player.h"
#include "ItemObject.h"
#include "Heart.h"
#include "VolatileHeart.h"

BloodBank::BloodBank(float x, float y) : GameObject("assets/StageObjects/BloodBank.png", x, y, 33, 44, 3) {

	solid = false;
	moveable = false;

	text = TextureManager::LoadText(Game::renderer, 24, {255, 255, 255}, "[bleed]");

	textRect.w = 60;
	textRect.h = 20;

}

BloodBank::~BloodBank() {}

void BloodBank::Update(LevelManager * game) {

	if(active) for(auto go : *(game->GetObjects())) if(dynamic_cast<Player *>(go) != nullptr) if(CollidesWith(go)) {
			collided = true;
			if(Game::inputManager->IsPressed(InputManager::interact)) {
				collided = false;
				go->DealDamage(1, game);
				if(rand() % 20 == 0) {
					switch(rand() % 2) {
						case 0:
							game->AddObject(new ItemObject(GetXCenter() - 12, y + height - 24, new Heart()));
							break;
						case 1:
							game->AddObject(new ItemObject(GetXCenter() - 12, y + height - 24, new VolatileHeart()));
							break;
					}
					active = false;
				} else ((Player *)go)->AddGold(20);
			}
	} else collided = false;

	textRect.x = (int)((x - Game::camera->GetX()) * Game::camera->GetScale());
	textRect.y = (int)((y - Game::camera->GetY()) * Game::camera->GetScale());

}

void BloodBank::RenderObject() {

	GameObject::RenderObject();

	if(collided) SDL_RenderCopy(Game::renderer, text, NULL, &textRect);

}
