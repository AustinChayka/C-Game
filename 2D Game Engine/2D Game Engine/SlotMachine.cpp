#include "SlotMachine.h"

#include "Player.h"
#include "ItemObject.h"
#include "Spirit.h"
#include "Explosion.h"

SlotMachine::SlotMachine(float x, float y) : GameObject("assets/StageObjects/SlotMachine.png", x, y, 33, 44, 3) {

	solid = false;
	moveable = false;

	s0 = rand() % 5;
	s1 = rand() % 5;
	s2 = rand() % 5;

	text = TextureManager::LoadText(Game::renderer, 24, {255, 255, 255}, "[roll]");

	textRect.w = 50;
	textRect.h = 20;

}

SlotMachine::~SlotMachine() {

	SDL_DestroyTexture(text);

}

void SlotMachine::Update(LevelManager * game) {

	if(rolling) {

		if(delay > 0) delay--;
		else {
			if(s0Count > 0) {
				s0Count--;
				s0++;
				if(s0 > 4) s0 = 0;
			}
			if(s1Count > 0) {
				s1Count--;
				s1++;
				if(s1 > 4) s1 = 0;
			}
			if(s2Count > 0) {
				s2Count--;
				s2++;
				if(s2 > 4) s2 = 0;
			}
			delay = 6;
		}

		if(s0Count == 0 && s1Count == 0 && s2Count == 0) {
			if(s0 == s1 && s1 == s2) {
				switch(s0) {
					case 0:
						((Player*)LevelManager::player)->AddGold(200);
						break;
					case 1:
						game->AddObject(new Explosion(GetXCenter(), GetYCenter(), 100, 2, this, game));
						active = false;
						break;
					case 2:
						game->AddObject(new Spirit(GetXCenter(), GetYCenter()));
						game->AddObject(new Spirit(GetXCenter(), GetYCenter()));
						break;
					case 3:
						game->AddObject(new ItemObject(GetXCenter() - 12, y + height - 24, 1));
						active = false;
						break;
					case 4:
						((Player*)LevelManager::player)->Heal(LevelManager::player->GetMaxHealth());
						break;
				}
			} else if(s0 == s1 || s0 == s2) {
				switch(s0) {
					case 0:
						((Player*)LevelManager::player)->AddGold(100);
						break;
					case 1:
						active = false;
						break;
					case 2:
						game->AddObject(new Spirit(GetXCenter(), GetYCenter()));
						break;
					case 3:
						game->AddObject(new ItemObject(GetXCenter() - 12, y + height - 24, 3));
						active = false;
						break;
					case 4:
						((Player*)LevelManager::player)->Heal(3);
						break;
				}
			} else if(s1 == s2) {
				switch(s1) {
					case 0:
						((Player*)LevelManager::player)->AddGold(100);
						break;
					case 1:
						active = false;
						break;
					case 2:
						game->AddObject(new Spirit(GetXCenter(), GetYCenter()));
						break;
					case 3:
						game->AddObject(new ItemObject(GetXCenter() - 12, y + height - 24, 3));
						active = false;
						break;
					case 4:
						((Player*)LevelManager::player)->Heal(3);
						break;
				}
			}
			rolling = false;
		}

	}

	for (auto go : *(game->GetObjects())) if(dynamic_cast<Player *>(go) != nullptr) if(CollidesWith(go)) {
		if(!rolling && active && ((Player *)go)->GetGold() >= 50) {
			collided = true;
			if(Game::inputManager->IsPressed(InputManager::interact)) {
				s0Count = rand() % 20 + 10;
				s1Count = rand() % 20 + 10;
				s2Count = rand() % 20 + 10;
				rolling = true;
				collided = false;
				((Player *)go)->AddGold(-50);
			}
		}
	} else collided = false;

	src0.y = src1.y = src2.y = 44;
	src0.w = src1.w = src2.w = 5;
	src0.h = src1.h = src2.h = 6;
	dest0.y = dest1.y = dest2.y = (int)((y  + 15 * 3 - Game::camera->GetY()) * Game::camera->GetScale());
	dest0.w = dest1.w = dest2.w = 5 * 3;
	dest0.h = dest1.h = dest2.h = 6 * 3;

	src0.x = s0 * 5;
	dest0.x = (int)((x + 8 * 3 - Game::camera->GetX()) * Game::camera->GetScale());
	src1.x = s1 * 5;
	dest1.x = (int)((x + 14 * 3 - Game::camera->GetX()) * Game::camera->GetScale());
	src2.x = s2 * 5;
	dest2.x = (int)((x + 20 * 3 - Game::camera->GetX()) * Game::camera->GetScale());

	textRect.x = (int)((x - Game::camera->GetX()) * Game::camera->GetScale());
	textRect.y = (int)((y - Game::camera->GetY()) * Game::camera->GetScale());

}

void SlotMachine::RenderObject() {

	GameObject::RenderObject();

	SDL_RenderCopy(Game::renderer, texture, &src0, &dest0);
	SDL_RenderCopy(Game::renderer, texture, &src1, &dest1);
	SDL_RenderCopy(Game::renderer, texture, &src2, &dest2);

	if(collided) SDL_RenderCopy(Game::renderer, text, NULL, &textRect);

}
