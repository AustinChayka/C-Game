#ifndef MenuState_h
#define MenuState_h

#include "StateManager.h"
#include "SDL.h"
#include "Button.h"
#include <vector>

class StateManager;
class Button;

class MenuState {

public:

	MenuState();

	~MenuState();

	virtual void Update(StateManager * sm);
	virtual void Render();

protected:

	SDL_Texture * text;
	SDL_Rect destRect;

	std::vector<Button *> buttons;

};

#endif