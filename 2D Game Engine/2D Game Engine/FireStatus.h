#ifndef FireStatus_h
#define FireStatus_h

#include "Status.h"

class FireStatus : public Status {

public:

	FireStatus();

	~FireStatus();

	void OnIncrement(GameObject * go, LevelManager * game);
	void OnEnd(GameObject * go, LevelManager * game);

};

#endif