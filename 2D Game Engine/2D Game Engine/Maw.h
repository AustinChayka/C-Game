#ifndef Maw_h
#define Maw_h

#include "Boss.h"

class Maw : public Boss {

public:

	Maw(float x, float y);

	~Maw();

	void Update(LevelManager * game);

	void OnCollision(GameObject * go, LevelManager * game);

	bool OverrideCollision(GameObject * go);

private:

	int delay = 120, subdelay = 20, shots = 3;

};

#endif