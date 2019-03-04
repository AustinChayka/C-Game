#include "LevelManager.h"

#include "Player.h"
#include "Platform.h"
#include "Box.h"
#include "Game.h"
#include "Block.h"
#include "Spirit.h"
#include "Pot.h"
#include "Door.h"
#include "Room.h"

GameObject * LevelManager::player = nullptr;

LevelManager::LevelManager() {

	player = new Player(0, 0);
	Game::camera->SetTarget(player);

	objects = new std::vector<GameObject *>;
	tiles = new std::vector<ImageTile *>;
	rooms = new std::vector<Room *>;
	allObjects = new std::vector<GameObject *>;

}

LevelManager::~LevelManager() {}

void LevelManager::LoadLevel(int n) {

	for(int i = 0; i < objects->size(); i++) if(objects->at(i) != player) delete objects->at(i);
	objects->clear();
	for(int i = 0; i < tiles->size(); i++) delete tiles->at(i);
	tiles->clear();
	for(int i = 0; i < rooms->size(); i++) delete rooms->at(i);
	rooms->clear();
	allObjects->clear();

	AddObject(player);
	
	GenerateLevel(n * 2 + 3, rand());

}

void LevelManager::GenerateLevel(int size, int seed) {

	srand(seed);
	
	float roomOffsetX = 0, roomOffsetY = 0;

	player->SetX(100);
	player->SetY(100);

	rooms->push_back(new Room(roomOffsetX, roomOffsetY, 0));
	roomOffsetX += 10 * 60;

	for(int i = 0; i < size; i++) {
		
		switch(rand() % 3) {

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

		}
		
	}
	
	rooms->push_back(new Room(roomOffsetX, roomOffsetY, 1));

}

void LevelManager::Update(StateManager * sm) {
	
	for(auto r : *rooms) {
		r->Update(this);
	}

	for(auto it : *tiles) it->Update();
		
	for(int i = 0; i < objects->size(); i++) {

		objects->at(i)->UpdateObject(this);
		if(objects->at(i)->IsDead()) {
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

	currentLevel++;
	reloaded = true;

}