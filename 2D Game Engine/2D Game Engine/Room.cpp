#include "Room.h"
#include "Spirit.h"
Room::Room(LevelManager * game, float init_x, float init_y, int blocksWidth, int blocksHeight,
	int leftDoorHeight, int rightDoorHeight, int entrance) {

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
	}
	
	if(blocksWidth == 20 && blocksHeight == 6) {

		switch(rand() % 2) {

			case 0:
				for(int i = 1; i < 4; i++) {
					ImageTile * tile = new ImageTile("assets/Banner.png",
						x + width / 4 * i, y + height / 2 - 60, 30, 40, 0, 0, 3, 1);
					SDL_SetTextureColorMod(tile->GetTexture(), 100, 100, 100);
					tiles.push_back(tile);
				}
				break;

			case 1:
				for(int i = 1; i < 4; i++)
					if(i) objects.push_back(new Pot(x + 100 + i * 16 * 3, y + height - 60 - 24 * 3, rand() % 4 == 0 ? true : false));
				objects.push_back(new Spirit(x + 200, y + 50));
				break;

		}

	} else if(blocksWidth == 8 && blocksHeight == 12) {

		objects.push_back(new Platform(x + 60, y + (leftDoorHeight + 2) * 60, 4));
		objects.push_back(new Block(x + 16 * 5 * 3 + 12, y + (leftDoorHeight + 2) * 60, 1, 1));
		tiles.push_back(new ImageTile("assets/Block.png", x + 16 * 5 * 3 + 12, y + (leftDoorHeight + 2) * 60,
			20, 20, 0, 3, 3, 2));

	}

}

Room::~Room() {



}

void Room::SetRevealed(bool r) {

	revealed = r;

}

bool Room::IsRevealed() {

	return revealed;

}

void Room::Update(LevelManager * game) {

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