#include "Room.h"

#include "Spirit.h"
#include "Slime.h"
#include "ItemObject.h"
#include "Spike.h"
#include "StageDoor.h"
#include "SoftPlatform.h"
#include "Box.h"
#include "DemonAlter.h"

Room::Room(float offX, float offY, int type) {

	switch(type) {

		case 0:
			Init(offX, offY, 10, 6, -1, 3, 0);
			objects.push_back(new StageDoor(x + 120, y + 5 * 60 - 48 * 3, false));
			break;

		case 1:
			Init(offX, offY, 10, 6, 3, -1, -1);
			objects.push_back(new StageDoor(x + 9 * 60 - 120, y + 5 * 60 - 48 * 3, true));
			break;

		case 2:
			Init(offX, offY, 20, 6, 3, 3, -1);
			objects.push_back(new Slime(x + 500, y + 100, 3));
			objects.push_back(new Slime(x + 800, y + 100, 3));
			for(int i = 1; i < 19 * (60 / 72.0f); i++) if(rand() % 2 == 1) {
				int l = rand() % 2 == 0 ? 0 : 3;
				ImageTile * tile = new ImageTile("assets/StageSlime.png",
					x + i * 72, y + 60, 24, 24, rand() % 4, 0, 3, l);
				SDL_SetTextureColorMod(tile->GetTexture(), l == 0 ? 100 : 255, l == 0 ? 100 : 255, l == 0 ? 100 : 255);
				tiles.push_back(tile);
			}
			for(int i = 1; i < 19 * (60 / 72.0f); i++) if(rand() % 2 == 1) {
				int l = rand() % 2 == 0 ? 0 : 3;
				ImageTile * tile = new ImageTile("assets/StageSlime.png",
					x + i * 72, y + 5 * 60 - 72, 24, 24, rand() % 4 + 4, 0, 3, l);
				SDL_SetTextureColorMod(tile->GetTexture(), l == 0 ? 100 : 255, l == 0 ? 100 : 255, l == 0 ? 100 : 255);
				tiles.push_back(tile);
			}
			break;

		case 3:
			Init(offX, offY, 20, 6, 3, 3, -1);
			for(int i = 1; i < 4; i++) {
				ImageTile * tile = new ImageTile("assets/Banner.png",
					x + width / 4 * i, y + height / 2 - 60, 30, 40, 0, 0, 3, 1);
				SDL_SetTextureColorMod(tile->GetTexture(), 100, 100, 100);
				tiles.push_back(tile);
			}
			objects.push_back(new Spirit(x + 700, y + 100));
			break;

		case 4:
			Init(offX, offY, 8, 12, 3, 9, -1);
			objects.push_back(new Platform(x + 60, y + 5 * 60, 4));
			objects.push_back(new Block(x + 16 * 5 * 3 + 12, y + 5 * 60, 1, 1));
			tiles.push_back(new ImageTile("assets/Block.png", x + 16 * 5 * 3 + 12, y + 5 * 60,
				20, 20, 0, 3, 3, 2));
			objects.push_back(new Spike(x + 60, y + 5 * 60 - 30));
			objects.push_back(new Spike(x + 120, y + 5 * 60 - 30));
			objects.push_back(new Spike(x + 180, y + 5 * 60 - 30));
			break;

		case 5:
			Init(offX, offY, 16, 16, 13, 3, -1);
			objects.push_back(new Block(x + 60, y + 11 * 60, 8, 1));
			for(int i = 0; i < 8; i++) tiles.push_back(new ImageTile("assets/Block.png", x + 60 * i, y + 11 * 60, 20, 20, 0, 2, 3, 2));
			tiles.push_back(new ImageTile("assets/Block.png", x + 60 * 8, y + 11 * 60, 20, 20, 3, 0, 3, 2));
			objects.push_back(new SoftPlatform(x + 9 * 60, y + 11 * 60, 3));
			objects.push_back(new SoftPlatform(x + 9 * 60, y + 13 * 60, 3));
			objects.push_back(new Block(x + 12 * 60, y + 11 * 60, 3, 1));
			for(int i = 0; i < 3; i++) tiles.push_back(new ImageTile("assets/Block.png", x + 60 * (i + 13), y + 11 * 60, 20, 20, 0, 2, 3, 2));
			tiles.push_back(new ImageTile("assets/Block.png", x + 60 * 12, y + 11 * 60, 20, 20, 4, 0, 3, 2));
			objects.push_back(new Block(x + 60, y + 7 * 60, 3, 1));
			for(int i = 0; i < 3; i++) tiles.push_back(new ImageTile("assets/Block.png", x + 60 * i, y + 7 * 60, 20, 20, 0, 2, 3, 2));
			tiles.push_back(new ImageTile("assets/Block.png", x + 60 * 3, y + 7 * 60, 20, 20, 3, 0, 3, 2));
			objects.push_back(new SoftPlatform(x + 4 * 60, y + 7 * 60, 3));
			objects.push_back(new SoftPlatform(x + 4 * 60, y + 9 * 60, 3));
			objects.push_back(new Block(x + 7 * 60, y + 7 * 60, 8, 1));
			for(int i = 0; i < 8; i++) tiles.push_back(new ImageTile("assets/Block.png", x + 60 * (i + 8), y + 7 * 60, 20, 20, 0, 2, 3, 2));
			tiles.push_back(new ImageTile("assets/Block.png", x + 60 * 7, y + 7 * 60, 20, 20, 4, 0, 3, 2));
			objects.push_back(new SoftPlatform(x + 14 * 60, y + 5 * 60, 1));
			objects.push_back(new Spike(x + 8 * 60, y + 15 * 60 - 30));
			objects.push_back(new Spike(x + 9 * 60, y + 15 * 60 - 30));
			objects.push_back(new Spike(x + 10 * 60, y + 15 * 60 - 30));
			objects.push_back(new Spike(x + 11 * 60, y + 15 * 60 - 30));
			objects.push_back(new Spike(x + 12 * 60, y + 15 * 60 - 30));
			objects.push_back(new Spike(x + 3 * 60, y + 11 * 60 - 30));
			objects.push_back(new Spike(x + 4 * 60, y + 11 * 60 - 30));
			objects.push_back(new Spike(x + 5 * 60, y + 11 * 60 - 30));
			objects.push_back(new Spike(x + 6 * 60, y + 11 * 60 - 30));
			objects.push_back(new Spike(x + 7 * 60, y + 11 * 60 - 30));
			break;

		case 6:
			Init(offX, offY, 8, 8, 5, 5, -1);
			if(rand() % 2 == 0) objects.push_back(new ItemObject(x + 4 * 60 - 12, y + 7 * 60 - 24, 0));
			else objects.push_back(new DemonAlter(x + 4 * 60 - 60, y + 7 * 60 - 150));
			break;

	}
}

Room::~Room() {
	
	for(int i = 0; i < objects.size(); i++) delete objects.at(i);
	objects.clear();
	for(int i = 0; i < tiles.size(); i++) delete tiles.at(i);
	tiles.clear();

}

void Room::SetRevealed(bool r) {

	revealed = r;

}

bool Room::IsRevealed() {

	return revealed;

}

void Room::Update(LevelManager * game) {

	if(!revealed) {
		door->UpdateObject(game);
		return;
	}

	for(auto it : tiles) it->Update();

	for(int i = 0; i < objects.size(); i++) {

		objects.at(i)->UpdateObject(game);
		if(objects.at(i)->IsDead()) {
			delete objects.at(i);
			objects.erase(objects.begin() + i);
			i--;
		}

	}

	if(LevelManager::player->GetX() + LevelManager::player->GetWidth() > x
		&& LevelManager::player->GetX() < x + width
		&& LevelManager::player->GetY() + LevelManager::player->GetHeight() > y
		&& LevelManager::player->GetY() < y + height) 
		active = true;
	else active = false;
		
}

void Room::Render(int layer) {

	for(auto it : tiles) if(revealed && it->GetLayer() == layer) it->Render();
	for(auto go : objects) if((revealed || go == door) && go->GetRenderLayer() == layer) go->RenderObject();
	
}

std::vector<GameObject*> * Room::GetObjects() {

	return &objects;

}

float Room::GetY() {

	return y;

}

float Room::GetX() {

	return x;

}

float Room::GetWidth() {

	return width;

}

float Room::GetHeight() {

	return height;

}

bool Room::IsActive() {

	return active;

}

void Room::Init(float init_x, float init_y, int blocksWidth, int blocksHeight, int leftDoorHeight, int rightDoorHeight, int entrance) {

	x = init_x;
	y = init_y;
	width = 60 * blocksWidth;
	height = 60 * blocksHeight;

	objects.push_back(new Block(x + 60, y, blocksWidth - 2, 1));
	objects.push_back(new Block(x + 60, y + 60 * (blocksHeight - 1), blocksWidth - 2, 1));
	if(leftDoorHeight == -1) objects.push_back(new Block(x, y, 1, blocksHeight));
	else {
		objects.push_back(new Block(x, y, 1, leftDoorHeight));
		objects.push_back(new Block(x, y + 60 * (leftDoorHeight + 2), 1, blocksHeight - leftDoorHeight - 2));
		for(int i = 0; i < 2; i++) {
			ImageTile * tile = new ImageTile("assets/Block.png", x, 
				y + (leftDoorHeight + i) * 60, 20, 20, 0, 0, 3, 0);
			SDL_SetTextureColorMod(tile->GetTexture(), 100, 100, 100);
			tiles.push_back(tile);
		}
		if(entrance == -1) {
			door = new Door(this, x - 18, y + leftDoorHeight * 60);
			objects.push_back(door);
			revealed = false;
		}
	}
	if(rightDoorHeight == -1) objects.push_back(new Block(x + 60 * (blocksWidth - 1), y, 1, blocksHeight));
	else {
		objects.push_back(new Block(x + 60 * (blocksWidth - 1), y, 1, rightDoorHeight));
		objects.push_back(new Block(x + 60 * (blocksWidth - 1), y + 60 * (rightDoorHeight + 2), 1, blocksHeight - rightDoorHeight - 2));
		for(int i = 0; i < 2; i++) {
			ImageTile * tile = new ImageTile("assets/Block.png", x + 60 * (blocksWidth - 1), 
				y + (rightDoorHeight + i) * 60, 20, 20, 0, 0, 3, 0);
			SDL_SetTextureColorMod(tile->GetTexture(), 100, 100, 100);
			tiles.push_back(tile);
		}
		if(entrance == 1) {
			door = new Door(this, x + 60 * (blocksWidth - 1) + 18, y + rightDoorHeight * 60);
			objects.push_back(door);
			revealed = false;
		}
	}

	for(int j = 1; j < blocksHeight - 1; j++) for(int i = 1; i < blocksWidth - 1; i++) {
		ImageTile * tile = new ImageTile("assets/Block.png", x + 60 * i, y + 60 * j, 20, 20, 0, 0, 3, 0);
		SDL_SetTextureColorMod(tile->GetTexture(), 100, 100, 100);
		tiles.push_back(tile);
	}

	for(int i = 0; i < blocksWidth; i++) {
		tiles.push_back(new ImageTile("assets/Block.png", x + 60 * i, y, 20, 20, 3, 2, 3, 2));
		tiles.push_back(new ImageTile("assets/Block.png", x + 60 * i, y + 60 * (blocksHeight - 1), 20, 20, 4, 2, 3, 2));
	}
	for(int i = 0; i < blocksHeight; i++) {
		if(leftDoorHeight == -1)
			tiles.push_back(new ImageTile("assets/Block.png", x, y + 60 * i, 20, 20, 1, 2, 3, 2));
		else if(i == leftDoorHeight + 2 && i != blocksHeight - 1)
			tiles.push_back(new ImageTile("assets/Block.png", x, y + 60 * i, 20, 20, 4, 1, 3, 2));
		else if(i != leftDoorHeight - 1 && i != leftDoorHeight && i != leftDoorHeight + 1 &&
			i != leftDoorHeight + 2)
			tiles.push_back(new ImageTile("assets/Block.png", x, y + 60 * i, 20, 20, 1, 2, 3, 2));
		else if(i == leftDoorHeight - 1)
			tiles.push_back(new ImageTile("assets/Block.png", x, y + 60 * i, 20, 20, 2, 1, 3, 2));
		if(rightDoorHeight == -1)
			tiles.push_back(new ImageTile("assets/Block.png", x + 60 * (blocksWidth - 1), y + 60 * i, 20, 20, 2, 2, 3, 2));
		else if(i != rightDoorHeight - 1 && i != rightDoorHeight && i != rightDoorHeight + 1 &&
			i != rightDoorHeight + 2)
			tiles.push_back(new ImageTile("assets/Block.png", x + 60 * (blocksWidth - 1), y + 60 * i, 20, 20, 2, 2, 3, 2));
		else if(i == rightDoorHeight - 1)
			tiles.push_back(new ImageTile("assets/Block.png", x + 60 * (blocksWidth - 1), y + 60 * i, 20, 20, 1, 1, 3, 2));
		else if(i == rightDoorHeight + 2 && i != blocksHeight - 1)
			tiles.push_back(new ImageTile("assets/Block.png", x + 60 * (blocksWidth - 1), y + 60 * i, 20, 20, 3, 1, 3, 2));
	}

}
