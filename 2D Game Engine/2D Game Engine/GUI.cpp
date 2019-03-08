#include "GUI.h"

#include "Player.h"
#include "Room.h"
#include "Item.h"

GUI::GUI(GameObject * p, StateManager * sm) {

	player = p;
	manager = sm;

}

GUI::~GUI() {



}

void GUI::Update() {

	if(showHealth > 0) showHealth--;
	if(showManaFatigue > 0) showManaFatigue--;
	if(showNewItem > 0) showNewItem--;
	
	if(player->GetHealth() != prevHealth || player->GetMaxHealth() != prevMaxHealth) showHealth = 180;
	if(((Player *)player)->GetManaFatigue() != prevManaFatigue) showManaFatigue = 180;
	if(prevItemsSize < ((Player *)player)->GetItems()->size()) showNewItem = 120;

	prevHealth = player->GetHealth();
	prevMaxHealth = player->GetMaxHealth();
	prevManaFatigue = ((Player *)player)->GetManaFatigue();
	prevItemsSize = ((Player *)player)->GetItems()->size();

	mapWidth = 0;
	for(auto r : *(manager->GetLevelManager()->GetRooms())) if(r->IsRevealed() && 
		((r->GetX() +  r->GetWidth() )/ 60) * 2 > mapWidth) 
		mapWidth = ((r->GetX() +  r->GetWidth() )/ 60) * 2;
	mapHeight = 0;
	for(auto r : *(manager->GetLevelManager()->GetRooms())) if(r->IsRevealed() &&
		((r->GetY() + r->GetHeight()) / 60) * 2 > mapHeight) 
		mapHeight = ((r->GetY() + r->GetHeight()) / 60) * 2;

}

void GUI::Render() {

	if(showHealth > 0) for(int i = 0; i < player->GetMaxHealth(); i++) {

		for(int y = 0; y < 25; y++) for(int x = 0; x < 10; x++) {

			if(i <= player->GetHealth()) {
				SDL_SetRenderDrawColor(Game::renderer, 255, 0, 0, 150);
				SDL_RenderDrawPoint(Game::renderer, x + 15 + i * 15, y + 15);
			} else {
				SDL_SetRenderDrawColor(Game::renderer, 100, 0, 0, 150);
				SDL_RenderDrawPoint(Game::renderer, x + 15 + i * 15, y + 15);
			}

		}

	}

	if(showManaFatigue > 0) for(int y = 0; y < ((Player *)player)->GetManaFatigue() * 20; y++) for(int x = 0; x < 15; x++) {

		SDL_SetRenderDrawColor(Game::renderer, 0, 0, 255, 150);
		SDL_RenderDrawPoint(Game::renderer, x + 15, Game::height - y - 15);

	}

	if(showNewItem > 0) {
		iconRect.x = Game::width / 2 - 24 * 2;
		iconRect.y = Game::height / 3;
		iconRect.w = 24 * 4;
		iconRect.h = 24 * 4;
		SDL_SetTextureAlphaMod(((Player *)player)->GetItems()->back()->GetTexture(), 100);
		SDL_RenderCopy(Game::renderer, ((Player *)player)->GetItems()->back()->GetTexture(), NULL, &iconRect);
		iconRect.x = Game::width / 2 -  ((Player *)player)->GetItems()->back()->GetNameLength() * 24;
		iconRect.y = Game::height / 3 - 100;
		iconRect.w = ((Player *)player)->GetItems()->back()->GetNameLength() * 48;
		iconRect.h = 100;
		SDL_SetTextureAlphaMod(((Player *)player)->GetItems()->back()->GetNameText(), 100);
		SDL_RenderCopy(Game::renderer, ((Player *) player)->GetItems()->back()->GetNameText(), NULL, &iconRect);
		iconRect.x = Game::width / 2 -  ((Player *)player)->GetItems()->back()->GetFlavorTextLength() * 12;
		iconRect.y = Game::height / 3 + 24 * 4;
		iconRect.w = ((Player *)player)->GetItems()->back()->GetFlavorTextLength() * 24;
		iconRect.h = 50;
		SDL_SetTextureAlphaMod(((Player *)player)->GetItems()->back()->GetFlavorText(), 100);
		SDL_RenderCopy(Game::renderer, ((Player *) player)->GetItems()->back()->GetFlavorText(), NULL, &iconRect);
	}
	
	for(auto r : *(manager->GetLevelManager()->GetRooms())) {
		
		if(r->IsActive()) SDL_SetRenderDrawColor(Game::renderer, 0, 150, 0, 100);
		else SDL_SetRenderDrawColor(Game::renderer, 0, 100, 0, 100);
		mapRect.x = (r->GetX() / 60) * 2 - 20 + Game::width - mapWidth;
		mapRect.y = (r->GetY() / 60) * 2 + 20 + Game::height - mapHeight;
		mapRect.w = (r->GetWidth() / 60) * 2;
		mapRect.h = (r->GetHeight() / 60) * 2;
		if(r->IsRevealed()) SDL_RenderFillRect(Game::renderer, &mapRect);

	}

	for(int i = 0; i < ((Player *) player)->GetItems()->size(); i++) {

		iconRect.x = Game::width - 24 - 12;
		iconRect.y = 12 + 36 * i;
		iconRect.w = iconRect.h = 24;
		itemTexture = ((Player *) player)->GetItems()->at(i)->GetTexture();
		SDL_SetTextureAlphaMod(itemTexture, 50);
		SDL_RenderCopy(Game::renderer, itemTexture, NULL, &iconRect);

	}

}

void GUI::SetPlayer(GameObject * p) {

	player = p;

}
