#include "LevelManager.h"

#include "Player.h"
#include "Platform.h"
#include "Box.h"
#include <fstream>
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

}

LevelManager::~LevelManager() {}

void LevelManager::LoadLevel(int n) {

	objects.clear();

	AddObject(player);
		
	switch(n) {

		case 0:
			GenerateLevel(1, NULL);
			
		default:
			break;
	}

	currentLevel = 0;

}

void LevelManager::GenerateLevel(int sizeX, int sizeY) {

	//TODO: rng level gen

	int n = 0;

	float roomOffsetX = 0, roomOffsetY = 0;

	for (int i = 0; i < sizeX; i++) {

		switch (n) {

			case 0:
				player->SetX(100);
				player->SetY(100);
				rooms.push_back(new Room(this, roomOffsetX, roomOffsetY, 20, 6, -1, 3, 0));
				roomOffsetX += 20 * 60;
				rooms.push_back(new Room(this, roomOffsetX, roomOffsetY, 20, 6, 3, 3, -1));
				roomOffsetX += 20 * 60;
				rooms.push_back(new Room(this, roomOffsetX, roomOffsetY, 20, 6, 3, 3, -1));
				roomOffsetX += 20 * 60;
				rooms.push_back(new Room(this, roomOffsetX, roomOffsetY, 20, 6, 3, 3, -1));
				roomOffsetX += 20 * 60;
				rooms.push_back(new Room(this, roomOffsetX, roomOffsetY, 20, 6, 3, -1, -1));
				break;

		}

	}

}

void LevelManager::Update(StateManager * sm) {

	for(auto r : rooms) r->Update(this);

	for(auto it : tiles) it->Update();
		
	for(int i = 0; i < objects.size(); i++) {

		objects.at(i)->UpdateObject(this);
		if(objects.at(i)->IsDead()) {
			delete objects.at(i);
			objects.erase(objects.begin() + i);
			i--;
		}

	}

	if(player->IsDead()) {
		sm->ChangeState(3);
		return;
	}

	Game::gui->Update();

}

void LevelManager::Render() {
	
	for(int layer = 0; layer <= 2; layer++) {

		for(auto r : rooms) r->Render(layer);
		for(auto it : tiles) if (it->GetLayer() == layer) it->Render();
		for(auto go : objects) if(go->GetRenderLayer() == layer) go->RenderObject();

	}

	Game::gui->Render();

}

void LevelManager::AddObject(GameObject * go) {

	objects.push_back(go);

}

void LevelManager::AddTile(ImageTile * it) {

	tiles.push_back(it);

}

std::vector<GameObject*> LevelManager::GetObjects() {

	std::vector<GameObject *> allObjects;

	allObjects.insert(allObjects.end(), objects.begin(), objects.end());
	for(auto r : rooms) allObjects.insert(allObjects.end(), r->GetObjects()->begin(), r->GetObjects()->end());

	return allObjects;

}

void LevelManager::NextLevel() {

	currentLevel++;
	LoadLevel(currentLevel);

}