#include "GUI.h"

#include "Player.h"
#include "Room.h"

GUI::GUI(GameObject * p, StateManager * sm) {

	player = p;
	manager = sm;

}

GUI::~GUI() {}

void GUI::Update() {

	if(showHealth > 0) showHealth--;
	if(showManaFatigue > 0) showManaFatigue--;
	
	if(player->GetHealth() != prevHealth) showHealth = 180;
	if(((Player*)player)->GetManaFatigue() != prevManaFatigue) showManaFatigue = 180;

	prevHealth = player->GetHealth();
	prevManaFatigue = ((Player*)player)->GetManaFatigue();

	mapWidth = 0;
	for(auto r : *(manager->GetLevelManager()->GetRooms())) if(r->IsRevealed()) mapWidth += (r->GetWidth() / 60) * 2;
	mapHeight = 0;
	for(auto r : *(manager->GetLevelManager()->GetRooms())) if(r->IsRevealed()) mapHeight += (r->GetHeight() / 60) * 2;

}

void GUI::Render() {

	if(showHealth > 0) for(int i = 0; i < player->GetHealth(); i++) {

		for(int y = 0; y < 25; y++) for(int x = 0; x < 10; x++) {

			SDL_SetRenderDrawColor(Game::renderer, 255, 0, 0, 150);
			SDL_RenderDrawPoint(Game::renderer, x + 15 + i * 15, y + 15);

		}

	}

	if(showManaFatigue > 0) for(int y = 0; y < ((Player*)player)->GetManaFatigue() * 20; y++) for(int x = 0; x < 15; x++) {

		SDL_SetRenderDrawColor(Game::renderer, 0, 0, 255, 150);
		SDL_RenderDrawPoint(Game::renderer, x + 15, Game::height - y - 15);

	}
	
	for(auto r : *(manager->GetLevelManager()->GetRooms())) {
		
		if(r->IsActive()) SDL_SetRenderDrawColor(Game::renderer, 0, 150, 0, 100);
		else SDL_SetRenderDrawColor(Game::renderer, 0, 100, 0, 100);
		mapRect.x = (r->GetX() / 60) * 2 - 20 + Game::width - mapWidth;
		mapRect.y = (r->GetY() / 60) * 2 + 20;
		mapRect.w = (r->GetWidth() / 60) * 2;
		mapRect.h = (r->GetHeight() / 60) * 2;
		if(r->IsRevealed()) SDL_RenderFillRect(Game::renderer, &mapRect);

	}

}
