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

	void ShowMessage(const char * message, Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha, int time);

private:

	GameObject * player;
	StateManager * manager;

	int showNewItem = 0, showText, textLen, goldCountNum = 0;

	const char * lastItemName;

	SDL_Rect mapRect, iconRect;
	float mapWidth, mapHeight;

	SDL_Texture * itemTexture;

	SDL_Texture * useItemReadyText, * messageText;

	SDL_Texture * heartIcon, * synergyIcon;
	SDL_Rect heartRect;

	SDL_Texture * goldCount;

};

#endif