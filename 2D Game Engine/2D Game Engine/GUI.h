#ifndef GUI_h
#define GUI_h

#include "GameObject.h"
#include "StateManager.h"

class Item;
class GameObject;
class StateManager;

class GUI {

public:

	GUI(GameObject * p, StateManager * sm);

	~GUI();

	void Update();

	void Render();

private:

	GameObject * player;
	StateManager * manager;

	int prevHealth = 0, showHealth = 0, showManaFatigue = 0, prevItemsSize = 0, showNewItem = 0;
	float prevManaFatigue = 0;

	SDL_Rect mapRect, iconRect;
	float mapWidth, mapHeight;

	SDL_Texture * itemTexture;

};

#endif