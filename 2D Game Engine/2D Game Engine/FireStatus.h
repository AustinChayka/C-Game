#ifndef FireStatus_h
#define FireStatus_h

#include "Status.h"

class FireStatus : public Status {

public:

	FireStatus(int i);

	~FireStatus();

	void OnApply(GameObject * go);
	void OnIncrement(GameObject * go, LevelManager * game);
	void OnEnd(GameObject * go, LevelManager * game);
	void OnUpdate(GameObject * go, LevelManager * game);

};

#endif