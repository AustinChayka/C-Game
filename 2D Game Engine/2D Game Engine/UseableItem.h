#ifndef UseableItem_h
#define UseableItem_h

#include "Item.h"

class UseableItem : public Item {

public:

	UseableItem(const char * path, const char * name, const char * flavor);

	~UseableItem();

	virtual bool OnUse(LevelManager * game, Player * p) = 0;

	virtual void Update(LevelManager * game, Player * p);

	int GetRecharge();
	int GetChargeTime();

protected:
	
	int rechargeTime = 3600, recharge = 0;

};

#endif