#include "LevelManager.h"

#include "Player.h"
#include "Platform.h"
#include "Box.h"
#include <fstream>

#include "Game.h"

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
			player->SetX(50);
			player->SetY(50);
			AddObject(new Platform(50, 300, 35));
			AddObject(new Platform(500, 100, 10));
			AddObject(new Box(300, -200));
			break;
			
		default:
			break;
	}

	currentLevel = 0;

}

void LevelManager::GenerateLevel(char * path, int sizeX, int sizeY) {

	//TODO: rng level gen

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

	Game::gui->Update();

}

void LevelManager::Render() {

	for(auto go : objects) go->RenderObject();

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