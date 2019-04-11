#ifndef Maw_h
#define Maw_h

#include "Boss.h"

class Maw : public Boss {

public:

	Maw(float x, float y);

	~Maw();

	void Update(LevelManager * game);

};

#endif