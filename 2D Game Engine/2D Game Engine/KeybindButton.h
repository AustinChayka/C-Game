#ifndef KeybindButton_h
#define KeybindButton_h

#include "Button.h"

class KeybindButton : public Button {

public:

	KeybindButton(float x, float y, int width, int height, const char * buttonText,
		float scale, int init_command);

	~KeybindButton();
	
	void Update(StateManager * sm, MenuState * m);

	void OnHold(StateManager * sm, MenuState * m);
	void OnPress(StateManager * sm, MenuState * m);
	void OnRelease(StateManager * sm, MenuState * m);

private:

	int command;
	bool listening;

};

#endif