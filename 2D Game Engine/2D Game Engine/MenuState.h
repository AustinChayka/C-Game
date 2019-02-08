#ifndef MenuState_h
#define MenuState_h

#include "StateManager.h"
#include "SDL.h"

class StateManager;

class MenuState {

public:

	MenuState();

	~MenuState();

	void Update(StateManager * sm);
	void Render();

private:

	SDL_Texture * text;
	SDL_Rect destRect;

};

#endif