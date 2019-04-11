#include "Boss.h"

#include "ItemObject.h"

Boss::Boss(const char * filepath, float x, float y, int width, int height, float scale, int h, const char * name) :
	Enemy(filepath, x, y, width, height, scale, h) {

	nameText = TextureManager::LoadText(Game::renderer, 24, {239, 197, 28}, name);
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

void Boss::RenderObject() {

	Enemy::RenderObject();

	SDL_RenderCopy(Game::renderer, nameText, NULL, &textRect);

	barRect.x = Game::width / 2 - 300;
	barRect.w = 600;
	SDL_SetRenderDrawColor(Game::renderer, 100, 100, 100, 255);
	SDL_RenderFillRect(Game::renderer, &barRect);
	
	barRect.x = Game::width / 2 - 300;
	barRect.w = 600 * health / (float)maxHealth;
	SDL_SetRenderDrawColor(Game::renderer, 239, 197, 28, 255);
	SDL_RenderFillRect(Game::renderer, &barRect);

}

void Boss::OnDeath(LevelManager * game, GameObject * go) {

	GameObject::OnDeath(game, go);

	game->AddObject(new ItemObject(GetXCenter() - 12, GetYCenter() - 12, 0));

}
