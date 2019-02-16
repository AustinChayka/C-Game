#ifndef Room_h
#define Room_h

#include "LevelManager.h"
#include "Block.h"

class Room {

public:

	Room(LevelManager * game, float init_x, float init_y, int blocksWidth, int blocksHeight);

	~Room();

private:

	float x, y;
	int width, height;

};

#endif