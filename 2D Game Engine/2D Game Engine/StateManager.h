#ifndef StateManager_h
#define StateManager_h

#include "LevelManager.h"
#include "MenuState.h"

class MenuState;
class LevelManager;

class StateManager {

public:

	StateManager();

	~StateManager();

	void Update();
	void Render();

	void ChangeState(int n);

private:

	LevelManager * levelManager;
	MenuState * mainMenu;
	MenuState * pauseMenu;

	int activeState = 1;
	bool stateChanged = false;

};

#endif