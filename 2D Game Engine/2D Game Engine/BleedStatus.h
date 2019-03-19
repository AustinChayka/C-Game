#ifndef BleedStatus_h
#define BleedStatus_h

#include "Status.h"

class BleedStatus : public Status {

public:

	BleedStatus(int i);

	~BleedStatus();

	void OnIncrement(GameObject * go, LevelManager * game);
	void OnEnd(GameObject * go, LevelManager * game);
	void OnUpdate(GameObject * go, LevelManager * game);

};

#endif