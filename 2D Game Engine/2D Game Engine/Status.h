#ifndef Status_h
#define Status_h

#include "GameObject.h"
#include "SDL.h"

class Status {

public:

	Status(const char * iconPath, int init_increment);

	~Status();

	void Update(GameObject * go, LevelManager * game);
	void Render(int y);

	virtual void OnIncrement(GameObject * go, LevelManager * game) = 0;
	virtual void OnEnd(GameObject * go, LevelManager * game) = 0;
	virtual void OnUpdate(GameObject * go, LevelManager * game) = 0;
	
	int GetIncrement();
	void SetIncrement(int i);

	bool IsActive();

protected:

	int increment = 0, maxStacks = 5;
	SDL_Texture * icon;
	SDL_Rect destRect, srcRect;

	int lifeTime = 60;
	int time;

};

#endif