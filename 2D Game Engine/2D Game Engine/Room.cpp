#include "Room.h"

Room::Room(LevelManager * game, float init_x, float init_y, int blocksWidth, int blocksHeight) {

	x = init_x;
	y = init_y;
	width = 60 * blocksWidth;
	height = 60 * blocksHeight;

	game->AddObject(new Block(x, y, blocksWidth, 1));
	game->AddObject(new Block(x, y + 60 * (blocksHeight - 1), blocksWidth, 1));
	game->AddObject(new Block(x, y + 60, 1, blocksHeight - 2));
	game->AddObject(new Block(x + 60 * (blocksWidth - 1), y + 60, 1, blocksHeight - 2));

	for(int j = 1; j < blocksHeight - 1; j++) for(int i = 1; i < blocksWidth - 1; i++) {
		ImageTile * tile = new ImageTile("assets/Block.png", x + 60 * i, y + 60 * j, 20, 20, 0, 0, 3, 0);
		SDL_SetTextureColorMod(tile->GetTexture(), 100, 100, 100);
		game->AddTile(tile);
	}

}

Room::~Room() {



}
