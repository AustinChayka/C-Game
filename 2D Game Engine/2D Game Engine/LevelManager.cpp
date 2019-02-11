#include "LevelManager.h"

#include "Player.h"
#include "Platform.h"
#include "Box.h"
#include <fstream>
#include "Game.h"
#include "Block.h"
#include "Spirit.h"
#include "Pot.h"

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
				AddObject(new Block(0 + roomOffsetX, 300 + roomOffsetY, 20, 1));
				AddObject(new Platform(550 + roomOffsetX, 100 + roomOffsetY, 10));
				AddObject(new Block(0 + roomOffsetX, 0 + roomOffsetY, 4, 1));
				AddObject(new Box(350 + roomOffsetX, -200 + roomOffsetY));
				AddObject(new Spirit(150 + roomOffsetX, -100 + roomOffsetY));
				AddObject(new Pot(650 + roomOffsetX, 100 -24 * 3 + roomOffsetY, true));
				AddObject(new Pot(750 + roomOffsetX, 100 -24 * 3 + roomOffsetY, false));
				roomOffsetX += 20 * 60;
				break;

		}

	}

}

void LevelManager::Update(StateManager * sm) {
		
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

		for(auto go : objects) if(go->GetRenderLayer() == layer) go->RenderObject();

	}

	Game::gui->Render();

}

void LevelManager::AddObject(GameObject * go) {

	objects.push_back(go);

}

std::vector<GameObject*> LevelManager::GetObjects() {

	return objects;

}

void LevelManager::NextLevel() {

	currentLevel++;
	LoadLevel(currentLevel);

}