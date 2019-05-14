#include "SacraficialAltar.h"

#include "Player.h"
#include "SacraficialDagger.h"
#include "CursedCandle.h"

SacraficialAltar::SacraficialAltar(float x, float y) : GameObject("assets/StageObjects/SacraficialAltar.png", x, y,
	40, 28, 3) {
	
	collidable = true;
	moveable = false;
	solid = false;

	text = TextureManager::LoadText(Game::renderer, 24, {255, 0, 0}, "[E] Light altar.");

	destRect.w = 30 * 10;
	destRect.h = 30;

}

SacraficialAltar::~SacraficialAltar() {}

void SacraficialAltar::Update(LevelManager * game) {
	
	if(!active) {
		tileX += .08f;
		if(tileX > 4) tileX = 0;
		return;
	}

	for (auto go : *(game->GetObjects())) if(dynamic_cast<Player *>(go) != nullptr) if(CollidesWith(go)) {
		for(int i = 0; i < ((Player *)go)->GetItems()->size(); i++) 
			if(dynamic_cast<CursedCandle *>(((Player *)go)->GetItems()->at(i)) != nullptr) {
		collided = true;
			if(Game::inputManager->IsPressed(InputManager::interact)) {
				active = false;
				collided = false;
				tileY = 1;
				((Player *)go)->AddItem(new SacraficialDagger(), game);
				delete ((Player *) go)->GetItems()->at(i);
				((Player *) go)->GetItems()->erase(((Player *) go)->GetItems()->begin() + i);
				Game::gui->ShowMessage("cursed candle has burnt out", 255, 255, 255, 255, 240);
			}
		}
	} else collided = false;

	destRect.x = (int)((GetXCenter() - Game::camera->GetX() - 150) * Game::camera->GetScale());
	destRect.y = (int)((y - Game::camera->GetY() - 40) * Game::camera->GetScale());

}

void SacraficialAltar::RenderObject() {

	GameObject::RenderObject();

	if(collided) SDL_RenderCopy(Game::renderer, text, NULL, &destRect);

}
