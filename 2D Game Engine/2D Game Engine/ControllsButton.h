#ifndef ControllsButton_h
#define ControllsButton_h

#include "Button.h"

class ControllsButton : public Button {

public:

	ControllsButton(float x, float y, int width, int height, float scale);

	~ControllsButton();

	void OnHold(StateManager * sm, MenuState * m);
	void OnPress(StateManager * sm, MenuState * m);
	void OnRelease(StateManager * sm, MenuState * m);

};

#endif