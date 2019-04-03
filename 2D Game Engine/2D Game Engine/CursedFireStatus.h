#ifndef CursedFireStatus_h
#define CursedFireStatus_h

#include "Status.h"

class CursedFireStatus : public Status {

public:

	CursedFireStatus(int i);

	~CursedFireStatus();

	void OnApply(GameObject * go);
	void OnIncrement(GameObject * go, LevelManager * game);
	void OnEnd(GameObject * go, LevelManager * game);
	void OnUpdate(GameObject * go, LevelManager * game);

private:

	int smokeDelay = 0, burnoutDelay = 0;

};

#endif