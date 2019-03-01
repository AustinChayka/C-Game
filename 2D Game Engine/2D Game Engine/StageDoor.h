#ifndef StageDoor_h
#define StageDoor_h

#include "GameObject.h"

class StageDoor : public GameObject {

public:

	StageDoor(float x, float y, bool init_exit);

	~StageDoor();

	void Update(LevelManager * game);

	void RenderObject();

private:

	bool collided, exit;

	SDL_Texture * text;
	SDL_Rect textRect;

};

#endif 