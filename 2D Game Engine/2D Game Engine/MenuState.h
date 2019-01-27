#ifndef MenuState_h
#define MenuState_h

#include "StateManager.h"

class StateManager;

class MenuState {

public:

	MenuState();

	~MenuState();

	void Update(StateManager * sm);
	void Render();

};

#endif