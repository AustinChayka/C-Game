#ifndef Block_h
#define Block_h

#include "GameObject.h"

class Block : public GameObject {

public:

	Block(float x, float y, int init_tilesWidth, int init_tilesHeight);

	~Block();

	void RenderObject();
	void Update(LevelManager * game);

	enum Wall {
		TOP = 0, 
		RIGHT = 1,
		BOTTOM = 2,
		LEFT = 3
	};

private:
	
	int tilesWidth, tilesHeight;

};

#endif