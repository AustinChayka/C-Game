#ifndef GameOverScreen_h
#define GameOverScreen_h

#include "MenuState.h"
class GameOverScreen : public MenuState {

public:

	GameOverScreen();

	~GameOverScreen();

	void Update(StateManager * sm);
	void Render();
	
};

#endif