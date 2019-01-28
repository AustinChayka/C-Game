#ifndef GUI_h
#define GUI_h

#include "GameObject.h"

class GUI {

public:

	GUI(GameObject * p);

	~GUI();

	void Update();

	void Render();

private:

	GameObject * player;

	int prevHealth = 0, showHealth = 0, showManaFatigue = 0;
	float prevManaFatigue = 0;

};

#endif