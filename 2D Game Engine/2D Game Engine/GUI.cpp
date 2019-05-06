#include "GUI.h"

#include "Player.h"
#include "Room.h"
#include "Item.h"
#include "UseableItem.h"
#include <typeinfo>

GUI::GUI(GameObject * p, StateManager * sm) {

	player = p;
	manager = sm;

	useItemReadyText = TextureManager::LoadText(Game::renderer, 24, {255, 255, 255}, "[Q]");

	heartIcon = TextureManager::LoadTexture(Game::renderer, "assets/Icons/HeartIcon.png");
	heartRect.w = 5;
	heartRect.h = 10;

	lastItemName = "";

}

GUI::~GUI() {



}

void GUI::Update() {

	if(showNewItem > 0) showNewItem--;
	if(showText > 0) showText--;
	
	if(((Player *) player)->GetItems()->size() > 0 && 
		lastItemName != typeid(*((Player *) player)->GetItems()->at(((Player *) player)->GetItems()->size() - 1)).name()) {
		showNewItem = 120;
		lastItemName = typeid(*((Player *) player)->GetItems()->at(((Player *) player)->GetItems()->size() - 1)).name();
	}

	mapWidth = 0;
	for(auto r : *(manager->GetLevelManager()->GetRooms())) if(r->IsRevealed() && 
		((r->GetX() +  r->GetWidth()) / 60) * 2 > mapWidth) 
		mapWidth = ((r->GetX() +  r->GetWidth() )/ 60) * 2;
	mapHeight = 0;
	for(auto r : *(manager->GetLevelManager()->GetRooms())) if(r->IsRevealed() &&
		((r->GetY() + r->GetHeight()) / 60) * 2 > mapHeight) 
		mapHeight = ((r->GetY() + r->GetHeight()) / 60) * 2;

}

void GUI::Render() {
	
	int offX = 15;
	for(int i = 0; i < player->GetMaxHealth(); i++) {

		if(i % 20 == 0) offX = 15;

		iconRect.w = 15;
		iconRect.h = 30;
		iconRect.x = offX + 15 * (i % 20);
		iconRect.y = 15 + 30 * (int)(i / 20);
				
		if(i < player->GetHealth()) {
			heartRect.x = 0;
		} else {
			heartRect.x = 10;
		}
		
		if(i % 2 == 1) {
			heartRect.x += 5;
			offX += 5;
		}

		SDL_RenderCopy(Game::renderer, heartIcon, &heartRect, &iconRect);

	}

	for(int y = 0; y < ((Player *)player)->GetManaFatigue() * 20; y++) for(int x = 0; x < 15; x++) {

		SDL_SetRenderDrawColor(Game::renderer, 0, 0, 255, 150);
		SDL_RenderDrawPoint(Game::renderer, x + 15, Game::height - y - 15);

	}

	if(showNewItem > 0) {
		iconRect.x = Game::width / 2 - 24 * 2;
		iconRect.y = Game::height / 3;
		iconRect.w = 24 * 4;
		iconRect.h = 24 * 4;
		SDL_SetTextureAlphaMod(((Player *)player)->GetItems()->back()->GetTexture(), 150);
		SDL_RenderCopy(Game::renderer, ((Player *)player)->GetItems()->back()->GetTexture(), NULL, &iconRect);
		iconRect.x = Game::width / 2 -  ((Player *)player)->GetItems()->back()->GetNameLength() * 24;
		iconRect.y = Game::height / 3 - 100;
		iconRect.w = ((Player *)player)->GetItems()->back()->GetNameLength() * 48;
		iconRect.h = 100;
		SDL_SetTextureAlphaMod(((Player *)player)->GetItems()->back()->GetNameText(), 150);
		SDL_RenderCopy(Game::renderer, ((Player *) player)->GetItems()->back()->GetNameText(), NULL, &iconRect);
		iconRect.x = Game::width / 2 -  ((Player *)player)->GetItems()->back()->GetFlavorTextLength() * 12;
		iconRect.y = Game::height / 3 + 24 * 4;
		iconRect.w = ((Player *)player)->GetItems()->back()->GetFlavorTextLength() * 24;
		iconRect.h = 50;
		SDL_SetTextureAlphaMod(((Player *)player)->GetItems()->back()->GetFlavorText(), 150);
		SDL_RenderCopy(Game::renderer, ((Player *) player)->GetItems()->back()->GetFlavorText(), NULL, &iconRect);
	}
	
	for(auto r : *(manager->GetLevelManager()->GetRooms())) {
		
		if(!r->IsRevealed()) continue;

		if(r->IsActive()) SDL_SetRenderDrawColor(Game::renderer, 0, 150, 0, 100);
		else SDL_SetRenderDrawColor(Game::renderer, 0, 100, 0, 100);
		mapRect.x = (r->GetX() / 60) * 2 - 15 + Game::width - mapWidth;
		mapRect.y = (r->GetY() / 60) * 2 - 15 + Game::height - mapHeight;
		mapRect.w = (r->GetWidth() / 60) * 2;
		mapRect.h = (r->GetHeight() / 60) * 2;
		SDL_RenderFillRect(Game::renderer, &mapRect);

	}

	for(int i = 0; i < ((Player *) player)->GetItems()->size(); i++) {
		
		iconRect.x = Game::width - 24 - 12;
		iconRect.y = 12 + 36 * i;
		iconRect.w = iconRect.h = 24;
		itemTexture = ((Player *) player)->GetItems()->at(i)->GetTexture();
		SDL_SetTextureAlphaMod(itemTexture, 100);
		SDL_RenderCopy(Game::renderer, itemTexture, NULL, &iconRect);

	}

	if(((Player *) player)->GetUseItem() != nullptr) {
		iconRect.x = 45;
		iconRect.y = Game::height - 48 - 15;
		iconRect.w = iconRect.h = 48;
		itemTexture = ((Player *) player)->GetUseItem()->GetTexture();
		SDL_SetTextureAlphaMod(itemTexture, (((Player *) player)->GetUseItem()->GetChargeTime() -
			((Player *) player)->GetUseItem()->GetRecharge()) * 255.0 / ((Player *) player)->GetUseItem()->GetChargeTime());
		SDL_RenderCopy(Game::renderer, itemTexture, NULL, &iconRect);
		if(((Player *)player)->GetUseItem()->GetRecharge() == 0) {
			iconRect.x = 45 + 48;
			iconRect.y = Game::height - 15 - 24;
			iconRect.w = 36;
			iconRect.h = 24;
			SDL_RenderCopy(Game::renderer, useItemReadyText, NULL, &iconRect);
		}
	}

	if(showText > 0) {

		iconRect.x = Game::width / 2 - textLen * 12;
		iconRect.y = 55;
		iconRect.w = 24 * textLen;
		iconRect.h = 50;
		SDL_RenderCopy(Game::renderer, messageText, NULL, &iconRect);

	}

}

void GUI::SetPlayer(GameObject * p) {

	player = p;

}

void GUI::ShowMessage(const char * message, Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha, int time) {

	if(messageText != nullptr) SDL_DestroyTexture(messageText);
	messageText = TextureManager::LoadText(Game::renderer, 24, {red, green, blue, alpha}, message);
	showText = time;
	textLen = strlen(message);

}
