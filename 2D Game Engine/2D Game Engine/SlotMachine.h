#ifndef SlotMachine_h
#define SlotMachine_h

#include "GameObject.h"

class SlotMachine : public GameObject {

public:

	SlotMachine(float x, float y);

	~SlotMachine();

	void Update(LevelManager * game);
	void RenderObject();

private:

	int s0 = 0, s1 = 0, s2 = 0, s0Count = 0, s1Count = 0, s2Count = 0, delay = 6;
	SDL_Rect src0, src1, src2, dest0, dest1, dest2, textRect;
	bool collided = false, rolling = false, active = true;
	SDL_Texture * text;

};

#endif