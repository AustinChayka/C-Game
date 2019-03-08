#ifndef RestartButton_h
#define RestartButton_h

#include "Button.h"
class RestartButton : public Button {

public:

	RestartButton(float x, float y, int width, int height, float scale);

	~RestartButton();

	void OnHold(StateManager * sm, MenuState * m);
	void OnPress(StateManager * sm, MenuState * m);
	void OnRelease(StateManager * sm, MenuState * m);

};

#endif