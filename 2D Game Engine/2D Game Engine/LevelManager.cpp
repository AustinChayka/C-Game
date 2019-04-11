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

	if(leftOverEnemies > 0) Game::gui->ShowMessage("something stirs ahead...", 255, 100, 100, 200, 120);

	srand(seed);
	
	float roomOffsetX = 0, roomOffsetY = 0;

	player->SetX(100);
	player->SetY(100);

	//AddObject(new Maw(400, 100));

	rooms->push_back(new Room(roomOffsetX, roomOffsetY, 0));
	roomOffsetX += 10 * 60;

	int treasureRoom = rand() % size;

	for(int i = 0; i < size; i++) {

		if(i == treasureRoom) {
			roomOffsetY -= 60 * 2;
			rooms->push_back(new Room(roomOffsetX, roomOffsetY, 6));
			roomOffsetX += 8 * 60;
			roomOffsetY += 60 * 2;
		}
		
		switch(rand() % 6) {

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
				
		}
		
	}
	
	rooms->push_back(new Room(roomOffsetX, roomOffsetY, 1));

	if(size == 3) AddObject(new ItemObject(400, 5 * 60 - 24, 2));

}

void LevelManager::Update(StateManager * sm) {
	
	for(auto r : *rooms) {
		r->Update(this);
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

	if(player->IsDead()) {
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
	
	for(int layer = 0; layer <= 3; layer++) {

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