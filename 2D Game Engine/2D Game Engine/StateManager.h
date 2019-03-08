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

	LevelManager * GetLevelManager();
	void SetLevelManager(LevelManager * l);

private:

	LevelManager * levelManager;
	MenuState * mainMenu;
	MenuState * pauseMenu;
	MenuState * gameOver;

	int activeState = 1;
	bool stateChanged = false;

};

#endif