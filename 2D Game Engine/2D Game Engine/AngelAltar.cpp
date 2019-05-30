#include "AngelAltar.h"

#include "Player.h"
#include "ItemObject.h"

AngelAltar::AngelAltar(float x, float y) : GameObject("assets/StageObjects/AngelAltar.png", x, y, 40, 50, 3) {

	collidable = true;
	moveable = false;
	solid = false;

	text = TextureManager::LoadText(Game::renderer, 24, {100, 150, 255}, "[repent]");

	textRect.w = 30 * 4;
	textRect.h = 30;

}


AngelAltar::~AngelAltar() {
	
	SDL_DestroyTexture(text);
	((Player *)LevelManager::player)->SetAllignment(((Player *)LevelManager::player)->GetAllignment() - 1);

}

void AngelAltar::Update(LevelManager * game) {

	if(!active) return;
	
	for (auto go : *(game->GetObjects())) if(dynamic_cast<Player *>(go) != nullptr) if(CollidesWith(go)) {
		if(go->GetMaxHealth() > 4) {
			collided = true;
			if(Game::inputManager->IsPressed(InputManager::interact)) {
				((Player *)go)->SetManaFatigue(((Player *)go)->GetMaxManaFatigue() - 3);
				active = false;
				collided = false;
				game->AddObject(new ItemObject(GetXCenter() - 12, y + 50 * 3 - 24, 4));
				((Player *)go)->SetAllignment(((Player *)go)->GetAllignment() + 2);
			}
		}
	} else collided = false;

	textRect.x = (int)((GetXCenter() - Game::camera->GetX() - 150) * Game::camera->GetScale());
	textRect.y = (int)((y - Game::camera->GetY() - 40) * Game::camera->GetScale());

}

void AngelAltar::RenderObject() {

	GameObject::RenderObject();

	if(collided) SDL_RenderCopy(Game::renderer, text, NULL, &textRect);

}
