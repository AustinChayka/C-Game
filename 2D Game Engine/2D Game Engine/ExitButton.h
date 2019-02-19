#ifndef ExitButton_h
#define ExitButton_h

#include "Button.h"

class ExitButton : public Button {

public:

	ExitButton(float x, float y, int width, int height, float scale);

	~ExitButton();

	void OnHold(StateManager * sm, MenuState * m);
	void OnPress(StateManager * sm, MenuState * m);
	void OnRelease(StateManager * sm, MenuState * m);

};

#endif