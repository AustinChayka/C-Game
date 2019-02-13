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
				player->SetX(200);
				player->SetY(200);
				AddObject(new Block(0 + roomOffsetX, 0 + roomOffsetY, 20, 1));
				for(int i = 0; i < 20; i++) AddTile(new ImageTile("assets/Block.png", i * 60 + roomOffsetX,
					0 + roomOffsetY, 20, 20, 3, 2, 3, 2));
				AddObject(new Block(0 + roomOffsetX, 60 + roomOffsetY, 1, 8));
				for(int i = 0; i < 10; i++) AddTile(new ImageTile("assets/Block.png", 0 + roomOffsetX, i * 60 + roomOffsetY,
					20, 20, 1, 2, 3, 2));
				AddObject(new Block(0 + roomOffsetX, 60 * 9 + roomOffsetY, 20, 1));
				for(int i = 0; i < 20; i++) AddTile(new ImageTile("assets/Block.png", i * 60 + roomOffsetX, 60 * 9 + roomOffsetY,
					20, 20, 4, 2, 3, 2));
				AddObject(new Block(19 * 60 + roomOffsetX, 60 + roomOffsetY, 1, 8));
				for(int i = 0; i < 10; i++) AddTile(new ImageTile("assets/Block.png", 19 * 60 + 1 + roomOffsetX, i * 60 + roomOffsetY,
					20, 20, 2, 2, 3, 2));
				AddObject(new Platform(12 * 60 + roomOffsetX + 25, 60 * 6 + roomOffsetY + 1, 7));
				AddObject(new Block(18 * 60 + roomOffsetX, 60 * 6 + roomOffsetY, 1, 1));
				AddObject(new Block(11 * 60 + roomOffsetX + 25, 60 * 6 + roomOffsetY, 1, 1));
				for(int y = 0; y < 9; y++) for(int x = 0; x < 20; x++)  {
					AddTile(new ImageTile("assets/Block.png", x * 60 + roomOffsetX, y * 60 + roomOffsetY, 20, 20, 0, 0, 3, 0));
					SDL_SetTextureColorMod(tiles.back()->GetTexture(), 100, 100, 100);
				}
				AddObject(new Pot(400 + roomOffsetX, 60 * 9 - 3 * 24 + roomOffsetY, true));
				AddObject(new Pot(300 + roomOffsetX, 60 * 9 - 3 * 24 + roomOffsetY, false));
				AddObject(new Pot(440 + roomOffsetX, 60 * 9 - 3 * 24 + roomOffsetY, false));
				AddObject(new Pot(360 + roomOffsetX, 60 * 9 - 3 * 24 + roomOffsetY, false));
				//AddObject(new Spirit(360 + roomOffsetX, 300 + roomOffsetY));
				//AddObject(new Spirit(360 + roomOffsetX, 400+ roomOffsetY));
				break;

		}

	}

}

void LevelManager::Update(StateManager * sm) {

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

	return objects;

}

void LevelManager::NextLevel() {

	currentLevel++;
	LoadLevel(currentLevel);

}