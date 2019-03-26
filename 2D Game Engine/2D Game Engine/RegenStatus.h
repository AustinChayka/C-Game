#ifndef RegenStatus_h
#define RegenStatus_h

#include "Status.h"

class RegenStatus : public Status {

public:

	RegenStatus(int i);

	~RegenStatus();
	
	void OnApply(GameObject * go) ;
	void OnIncrement(GameObject * go, LevelManager * game);
	void OnEnd(GameObject * go, LevelManager * game);
	void OnUpdate(GameObject * go, LevelManager * game);

};

#endif