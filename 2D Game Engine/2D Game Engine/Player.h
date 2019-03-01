#ifndef Player_h
#define Player_h

#include "GameObject.h"

class Item;

class Player : public GameObject {

public:

	Player(float x, float y);
	~Player();
	
	void Update(LevelManager * game);
	void RenderObject();
	
	float GetManaFatigue();

	void DealDamage(int d, LevelManager * game, GameObject * go);

	void AddItem(Item * item, LevelManager * game);

	std::vector<Item *> * GetItems();

private:

	bool left = false, right = false, attack = false, attackLock = false;

	float maxSpeed = 7, acceleration = .6f, jumpPower = 11.5f, manaFatigue = 10;

	int dir = 1, shotDelay = 30, shot = 0, smokeDelay = 0, dash = 0;

	std::vector<Item *> * items;

};

#endif