#ifndef PoisonStatus_h
#define PoisonStatus_h

#include "Status.h"
class PoisonStatus : public Status {

public:

	PoisonStatus(int i);

	~PoisonStatus();

	void OnApply(GameObject * go);
	void OnIncrement(GameObject * go, LevelManager * game);
	void OnEnd(GameObject * go, LevelManager * game);
	void OnUpdate(GameObject * go, LevelManager * game);

private:

	int delay = 0;

};

#endif