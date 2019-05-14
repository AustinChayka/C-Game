#include "Door.h"

Door::Door(Room * init_room, float x, float y) : GameObject("assets/StageObjects/Door.png", x, y, 20, 40, 3) {

	room = init_room;

	renderLayer = 0;

	collidable = true;
	moveable = false;
	solid = true;

	text = TextureManager::LoadText(Game::renderer, 24, {255, 255, 255, 200}, "[use]");
	textRect.w = 50;
	textRect.h = 20;

}

Door::~Door() {

	SDL_DestroyTexture(text);

}

void Door::Update(LevelManager * game) {

	x -= 2;
	width += 4;

	for (auto go : *(game->GetObjects())) if(dynamic_cast<Player *>(go) != nullptr) if(CollidesWith(go)) {
		collided = true;
		if(Game::inputManager->IsPressed(InputManager::interact)) {
			closed = !closed;
			if(!room->IsRevealed()) room->SetRevealed(true);
		}
	} else collided = false;

	x += 2;
	width -= 4;
	
}

void Door::UpdateObject(LevelManager * game) {

	if(closed) {
		width = 8 * scale;
	} else {
		width = 20 * scale;
	}

	GameObject::UpdateObject(game);

	solid = closed;

	if(!closed) {
		srcRect.x = 0;
		srcRect.w = 20;
	} else {
		srcRect.x = 20;
		srcRect.w = 8;
		destRect.w = 8 * scale;
	}

	textRect.x = (int)((x - Game::camera->GetX()) * Game::camera->GetScale());
	textRect.y = (int)((y - Game::camera->GetY()) * Game::camera->GetScale());

}

void Door::RenderObject() {

	GameObject::RenderObject();

	if(collided) SDL_RenderCopy(Game::renderer, text, NULL, &textRect);

}