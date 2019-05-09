#ifndef ConfusedStatus_h
#define ConfusedStatus_h

#include "Status.h"

class ConfusedStatus : public Status {

public:

	ConfusedStatus(int i);

	~ConfusedStatus();

	void OnApply(GameObject * go);
	void OnIncrement(GameObject * go, LevelManager * game);
	void OnEnd(GameObject * go, LevelManager * game);
	void OnUpdate(GameObject * go, LevelManager * game);

};

#endif