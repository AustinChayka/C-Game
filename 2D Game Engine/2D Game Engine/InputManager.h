#ifndef InputManager_h
#define InputManager_h

#include "SDL.h"

class InputManager {

public:

	InputManager();

	~InputManager();

	enum Command {

		left = 0,
		right = 1,
		jump = 2,
		down = 3,
		shoot = 4,
		croutch = 5,
		interact = 6,
		useItem = 7,
		dash = 8

	};

	void Update(SDL_Event * event);

	bool IsPressed(int k);
	bool IsHeld(int k);
	bool IsReleased(int k);
	bool IsDown(int k);

	void RebindCommand(int command, int key);
	void FlashSaveControlLayout();
	void RandomizeCommands();
	void ResetCommands();

	SDL_Event * GetLastEvent();

private:

	int numCommands = 9;

	int commands[9], commandsFlash[9];
	bool commandTriggers[9][2];

	SDL_Event * lastEvent;

};

#endif