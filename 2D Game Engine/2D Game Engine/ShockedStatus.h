#ifndef ShockedStatus_h
#define ShockedStatus_h

#include "Status.h"

class ShockedStatus : public Status {

public:

	ShockedStatus(int i);

	~ShockedStatus();

	void OnApply(GameObject * go);
	void OnIncrement(GameObject * go, LevelManager * game);
	void OnEnd(GameObject * go, LevelManager * game);
	void OnUpdate(GameObject * go, LevelManager * game);

private:

	int transferDelay = 0;

};

#endif