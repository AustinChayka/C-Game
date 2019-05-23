#include "Boss.h"

#include "ItemObject.h"
#include "Room.h"

Boss::Boss(const char * filepath, float x, float y, int width, int height, float scale, int h, const char * name) :
	Enemy(filepath, x, y, width, height, scale, h) {

	red = 239;
	green = 197;
	blue = 28;

	nameText = TextureManager::LoadText(Game::renderer, 24, {red, green, blue}, name);
	textRect.x = Game::width / 2 - strlen(name) * 12;
	textRect.y = Game::height - 90;
	textRect.w = strlen(name) * 24;
	textRect.h = 50;

	barRect.y = Game::height - 35;
	barRect.h = 20;

}

Boss::Boss(const char * filepath, float x, float y, int width, int height, float scale, int h, const char * name,
	int init_red, int init_green, int init_blue) :
	Enemy(filepath, x, y, width, height, scale, h) {

	red = init_red;
	green = init_green;
	blue = init_blue;

	nameText = TextureManager::LoadText(Game::renderer, 24, {red, green, blue}, name);
	textRect.x = Game::width / 2 - strlen(name) * 12;
	textRect.y = Game::height - 90;
	textRect.w = strlen(name) * 24;
	textRect.h = 50;

	barRect.y = Game::height - 35;
	barRect.h = 20;

}

Boss::~Boss() {

	SDL_DestroyTexture(nameText);

}

void Boss::Update(LevelManager * game) {

	Enemy::Update(game);

	if(init) {
		for(int i = 0; i < game->GetRooms()->size() - 1; i++) if(game->GetRooms()->at(i)->IsRevealed() &&
			!game->GetRooms()->at(i + 1)->IsRevealed()) for(auto go : *game->GetRooms()->at(i + 1)->GetObjects())
			if(dynamic_cast<Door *>(go) != nullptr) ((Door *)go)->SetLocked(true);
		init = false;
	}

	if(!dead) Game::camera->SetTarget((GetXCenter() + LevelManager::player->GetXCenter()) / 2,
		(GetYCenter() + LevelManager::player->GetYCenter()) / 2);

	if(healthBarWidth > 600 * health / (float)maxHealth) 
		healthBarWidth -= 1;
	else if(healthBarWidth < 600 * health / (float)maxHealth) 
		healthBarWidth += 1;
}

void Boss::RenderObject(int l) {

	Enemy::RenderObject(l);
	if(l == 4) {

		if(target == nullptr || DistanceToSquared(target) > 2000 * 2000) return;

		SDL_RenderCopy(Game::renderer, nameText, NULL, &textRect);

		barRect.x = Game::width / 2 - 300;
		barRect.w = 600;
		SDL_SetRenderDrawColor(Game::renderer, 100, 100, 100, 255);
		SDL_RenderFillRect(Game::renderer, &barRect);

		barRect.x = Game::width / 2 - 300;
		barRect.w = healthBarWidth;
		SDL_SetRenderDrawColor(Game::renderer, red, green, blue, 255);
		SDL_RenderFillRect(Game::renderer, &barRect);

		if(healthBarWidth > 600 * health / (float)maxHealth) {
			barRect.x = Game::width / 2 - 300 + healthBarWidth;
			barRect.w = 600 * health / (float)maxHealth - healthBarWidth;
			SDL_SetRenderDrawColor(Game::renderer, 100, 0, 0, 255);
		} else if(healthBarWidth < 600 * health / (float)maxHealth) {
			barRect.x = Game::width / 2 - 300 + 600 * health / (float)maxHealth;
			barRect.w = healthBarWidth - 600 * health / (float)maxHealth;
			SDL_SetRenderDrawColor(Game::renderer, 0, 100, 0, 255);
		}
		SDL_RenderFillRect(Game::renderer, &barRect);

	}

}

void Boss::OnDeath(LevelManager * game, GameObject * go) {

	GameObject::OnDeath(game, go);

	Game::camera->SetTarget(LevelManager::player);
	for(int i = 0; i < game->GetRooms()->size() - 1; i++) if(game->GetRooms()->at(i)->IsRevealed() &&
		!game->GetRooms()->at(i + 1)->IsRevealed()) for(auto go : *game->GetRooms()->at(i + 1)->GetObjects())
		if(dynamic_cast<Door *>(go) != nullptr) ((Door *)go)->SetLocked(false);

	if(item != nullptr) game->AddObject(new ItemObject(GetXCenter() - 12, GetYCenter() - 12, item));

}
