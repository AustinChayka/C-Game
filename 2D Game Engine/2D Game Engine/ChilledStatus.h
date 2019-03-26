#ifndef ChilledStatus_h
#define ChilledStatus_h

#include "Status.h"

class ChilledStatus : public Status {

public:

	ChilledStatus(int i);

	~ChilledStatus();
	
	void OnApply(GameObject * go);
	void OnIncrement(GameObject * go, LevelManager * game);
	void OnEnd(GameObject * go, LevelManager * game);
	void OnUpdate(GameObject * go, LevelManager * game);

};

#endif