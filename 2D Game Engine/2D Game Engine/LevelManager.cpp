#include "LevelManager.h"

#include <ctime>
#include "Player.h"
#include "Platform.h"
#include "Box.h"
#include "Game.h"
#include "Block.h"
#include "Spirit.h"
#include "Pot.h"
#include "Door.h"
#include "Room.h"
#include "Projectile.h"
#include "ItemObject.h"
#include "Maw.h"
#include "CursedCandle.h"
#include "Error.h"

GameObject * LevelManager::player = nullptr;

LevelManager::LevelManager() {

	player = new Player(0, 0);
	Game::camera->SetTarget(player);

	objects = new std::vector<GameObject *>;
	tiles = new std::vector<ImageTile *>;
	rooms = new std::vector<Room *>;
	allObjects = new std::vector<GameObject *>;

}

LevelManager::~LevelManager() {

	for(int i = 0; i < objects->size(); i++) if(objects->at(i) != player) delete objects->at(i);
	objects->clear();
	for(int i = 0; i < tiles->size(); i++) delete tiles->at(i);
	tiles->clear();
	for(int i = 0; i < rooms->size(); i++) delete rooms->at(i);
	rooms->clear();
	allObjects->clear();

	delete player;
	player = nullptr;

	delete objects;
	objects = nullptr;
	delete tiles;
	tiles = nullptr;
	delete rooms;
	rooms = nullptr;
	delete allObjects;
	allObjects = nullptr;

}

void LevelManager::LoadLevel(int n) {

	for(int i = 0; i < objects->size(); i++) if(objects->at(i) != player) delete objects->at(i);
	objects->clear();
	for(int i = 0; i < tiles->size(); i++) delete tiles->at(i);
	tiles->clear();
	for(int i = 0; i < rooms->size(); i++) delete rooms->at(i);
	rooms->clear();
	allObjects->clear();

	AddObject(player);
	
	GenerateLevel(n * 2 + 3, time(0));

}

void LevelManager::GenerateLevel(int size, int seed) {

	if(leftOverEnemies > 5) Game::gui->ShowMessage("something stirs ahead.", 255, 100, 100, 200, 180);

	srand(seed);
	
	float roomOffsetX = 0, roomOffsetY = 0;

	player->SetX(100);
	player->SetY(100);
	
	rooms->push_back(new Room(roomOffsetX, roomOffsetY, 0));
	roomOffsetX += 10 * 60;
	/*
	roomOffsetY -= 9 * 60;
	rooms->push_back(new Room(roomOffsetX, roomOffsetY, 13));
	roomOffsetY += 9 * 60;
	roomOffsetX += 20 * 60;
	*/
	int treasureRoom = rand() % size, specialRoom = -1;
	
	if(rand() % 10 > 8 - 8 * specialRoomSkips / 4.0f) {
		specialRoom = rand() % size;
		specialRoomSkips = 0;
	} else specialRoomSkips++;
	
	for(int i = 0; i < size; i++) {

		if(i == treasureRoom) {
			roomOffsetY -= 60 * 2;
			rooms->push_back(new Room(roomOffsetX, roomOffsetY, 6));
			roomOffsetX += 8 * 60;
			roomOffsetY += 60 * 2;
		}

		if(i == specialRoom) {

			int n = 0;

			if(!IsBlacklisted(3)) n = 3;

			if(player->GetHealth() <= player->GetMaxHealth() / 2) n = 2;

			for(auto item : *((Player *) player)->GetItems()) {
				if(dynamic_cast<CursedCandle *>(item) != nullptr) n = 1;
			}
						
			if(IsBlacklisted(n)) continue;

			switch(n) {

				case 0:
					roomOffsetY -= 60 * 2;
					rooms->push_back(new Room(roomOffsetX, roomOffsetY, 6));
					roomOffsetX += 8 * 60;
					roomOffsetY += 60 * 2;
					break;

				case 1:
					roomOffsetY -= 60 * 2;
					rooms->push_back(new Room(roomOffsetX, roomOffsetY, 10));
					roomOffsetX += 8 * 60;
					roomOffsetY += 60 * 2;
					specialRoomsBlacklist.push_back(1);
					break;

				case 2:
					roomOffsetY -= 60 * 2;
					rooms->push_back(new Room(roomOffsetX, roomOffsetY, 11));
					roomOffsetX += 8 * 60;
					roomOffsetY += 60 * 2;
					break;

				case 3:
					roomOffsetY -= 60 * 2;
					rooms->push_back(new Room(roomOffsetX, roomOffsetY, 12));
					roomOffsetX += 12 * 60;
					roomOffsetY += 60 * 2;
					specialRoomsBlacklist.push_back(3);
					break;

			}

		}
		
		switch(rand() % 7) {

			case 0:
				rooms->push_back(new Room(roomOffsetX, roomOffsetY, 2));
				roomOffsetX += 20 * 60;
				break;

			case 1:
				rooms->push_back(new Room(roomOffsetX, roomOffsetY, 3));
				roomOffsetX += 20 * 60;
				break;

			case 2:
				rooms->push_back(new Room(roomOffsetX, roomOffsetY, 4));
				roomOffsetX += 8 * 60;
				roomOffsetY += 6 * 60;
				break;

			case 3:
				roomOffsetY -= 10 * 60;
				rooms->push_back(new Room(roomOffsetX, roomOffsetY, 5));
				roomOffsetX += 16 * 60;
				break;

			case 4:
				roomOffsetY -= 14 * 60;
				rooms->push_back(new Room(roomOffsetX, roomOffsetY, 7));
				roomOffsetX += 10 * 60;
				break;

			case 5:
				rooms->push_back(new Room(roomOffsetX, roomOffsetY, 8));
				roomOffsetX += 16 * 60;
				break;

			case 6:
				roomOffsetY -= 5 * 60;
				rooms->push_back(new Room(roomOffsetX, roomOffsetY, 9));
				roomOffsetX += 25 * 60;
				roomOffsetY += 5 * 60;
				break;
								
		}
		
	}
	   
	if(currentLevel != 0 && currentLevel % 3 == 0) {
		roomOffsetY -= 9 * 60;
		rooms->push_back(new Room(roomOffsetX, roomOffsetY, 13));
		roomOffsetY += 9 * 60;
		roomOffsetX += 20 * 60;
	}
	
	rooms->push_back(new Room(roomOffsetX, roomOffsetY, 1));
	if(leftOverEnemies > 5) {
		rooms->at(rooms->size() - 1)->AddObject(new Maw(roomOffsetX + 260, roomOffsetY + 100));
		leftOverEnemies = 0;
	}

	if(size == 3) {
		if(rand() % 20 == 0) AddObject(new ItemObject(400, 5 * 60 - 24 - 45, new Error()));
		else AddObject(new ItemObject(400, 5 * 60 - 24 - 45, 2));
		AddTile(new ImageTile("assets/StageObjects/Pedestal.png", 400 - 18, 5 * 60 - 45, 20, 15, 0, 0, 3, 2));
	}

}

void LevelManager::Update(StateManager * sm) {

	bool escaped = true;
	
	for(auto r : *rooms) {
		r->Update(this);
		if(r->IsActive()) escaped = false;
	}

	for(auto it : *tiles) it->Update();
		
	for(int i = 0; i < objects->size(); i++) {

		objects->at(i)->UpdateObject(this);
		if(objects->at(i)->IsDead() && dynamic_cast<Player *>(objects->at(i)) == nullptr) {
			delete objects->at(i);
			objects->erase(objects->begin() + i);
			i--;
		}

	}

	if(player->IsDead() || escaped) {
		sm->ChangeState(3);
		return;
	}

	Game::gui->Update();

	if(reloaded) {
		LoadLevel(currentLevel);
		reloaded = false;
		Game::camera->SetPos(player->GetXCenter() - Game::width / 2, player->GetYCenter() - Game::height / 2);
	}

	   
}

void LevelManager::Render() {
	
	for(int layer = 0; layer <= 4; layer++) {

		for(auto r : *rooms) r->Render(layer);
		for(auto it : *tiles) if (it->GetLayer() == layer) it->Render();
		for(auto go : *objects) if(go->GetRenderLayer() == layer) go->RenderObject();
		((Player *)player)->RenderItems(layer);

	}

	Game::gui->Render();

}

void LevelManager::AddObject(GameObject * go) {

	objects->push_back(go);

}

void LevelManager::AddTile(ImageTile * it) {

	tiles->push_back(it);

}

std::vector<Room*> * LevelManager::GetRooms() {

	return rooms;

}

std::vector<GameObject*> * LevelManager::GetObjects() {

	allObjects->clear();
	allObjects->insert(allObjects->end(), objects->begin(), objects->end());
	for(auto r : *rooms) allObjects->insert(allObjects->end(), r->GetObjects()->begin(), r->GetObjects()->end());
	
	return allObjects;

}

void LevelManager::NextLevel() {

	for(auto go : *GetObjects()) if(dynamic_cast<Enemy *>(go) != nullptr && dynamic_cast<Player *>(go) == nullptr) leftOverEnemies++;

	currentLevel++;
	reloaded = true;

}

bool LevelManager::IsBlacklisted(int r) {

	for(auto n : specialRoomsBlacklist) if(n == r) return true;

	return false;

}
