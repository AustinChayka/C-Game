#ifndef KeybindMenu_h
#define KeybindMenu_h

#include "MenuState.h"

class KeybindMenu : public MenuState {

public:

	KeybindMenu();

	~KeybindMenu();

	void Render();

private:

	SDL_Texture *left, *right, *jump, *down, *shoot, *interact, *useItem, *croutch, *dash;
	SDL_Rect textRect;

};

#endif