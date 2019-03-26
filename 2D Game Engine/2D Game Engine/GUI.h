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

	void SetPlayer(GameObject * p);

private:

	GameObject * player;
	StateManager * manager;

	int prevItemsSize = 0, showNewItem = 0;

	SDL_Rect mapRect, iconRect;
	float mapWidth, mapHeight;

	SDL_Texture * itemTexture;

	SDL_Texture * useItemReadyText;

	SDL_Texture * heartIcon;
	SDL_Rect heartRect;

};

#endif