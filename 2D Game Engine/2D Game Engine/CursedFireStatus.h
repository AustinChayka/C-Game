#ifndef CursedFireStatus_h
#define CursedFireStatus_h

#include "Status.h"

class CursedFireStatus : public Status {

public:

	CursedFireStatus(int i);

	~CursedFireStatus();

	void OnIncrement(GameObject * go, LevelManager * game);
	void OnEnd(GameObject * go, LevelManager * game);
	void OnUpdate(GameObject * go, LevelManager * game);

};

#endif