#ifndef Room_h
#define Room_h

#include "LevelManager.h"
#include "Block.h"
#include "Door.h"
#include <vector>
#include "Pot.h"
#include "Platform.h"

class Room {

public:

	Room(float init_x, float init_y, int type);

	~Room();

	void SetRevealed(bool r);
	bool IsRevealed();

	void Update(LevelManager * game);
	void Render(int layer);

	std::vector<GameObject *> * GetObjects();

	float GetY();
	float GetX();
	float GetWidth();
	float GetHeight();

	bool IsActive();
	
private:

	void Init(float init_x, float init_y, int blocksWidth, int blocksHeight, 
		int leftDoorHeight, int rightDoorHeight, int entrance);

	float x, y;
	int width, height;
	bool revealed = true, active;

	GameObject * door;

	std::vector<GameObject *> objects;
	std::vector<ImageTile *> tiles;

};

#endif