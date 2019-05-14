#ifndef Enemy_h
#define Enemy_h

#include "GameObject.h"

#include "Status.h"

class Enemy : public GameObject {

public:

	Enemy(const char * filepath, float x, float y, int width, int height, float scale, int h);

	~Enemy();

	virtual void Update(LevelManager * game);

	virtual void RenderObject();

	virtual void DealDamage(int d, LevelManager * game, GameObject * go);
	virtual void OnDeath(LevelManager * game, GameObject * go);

	void AddStatus(Status * s);
	virtual bool OverrideStatus(Status * s);

protected:

	GameObject * target;

	std::vector<Status *> statuses;

};

#endif