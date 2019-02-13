#ifndef PlayButton_h
#define PlayButton_h

#include "Button.h"

class PlayButton : public Button {

public:

	PlayButton(float x, float y, int width, int height, float scale);

	~PlayButton();

	void OnHold(StateManager * sm, MenuState * m);
	void OnPress(StateManager * sm, MenuState * m);
	void OnRelease(StateManager * sm, MenuState * m);

};

#endif