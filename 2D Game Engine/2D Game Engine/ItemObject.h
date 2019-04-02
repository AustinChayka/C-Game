#ifndef ItemObject_h
#define ItemObject_h

#include "GameObject.h"

#include "Item.h"
#include <vector>

class ItemObject : public GameObject {

public:

	ItemObject(float x, float y, int pool);

	~ItemObject();

	void Update(LevelManager * game);

	void RenderObject();

	void GenerateItem(int pool);
	
	static std::vector<std::vector<int>* > * items;

private:

	Item * item;
	SDL_Texture * text;
	SDL_Rect textRect;

	bool collided = false;
	
};

#endif