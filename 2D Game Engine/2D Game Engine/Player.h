#ifndef Player_h
#define Player_h

#include "Enemy.h"

class Item;
class Projectile;
class UseableItem;

class Player : public Enemy {

public:

	Player(float x, float y);
	~Player();
	
	void Update(LevelManager * game);
	void RenderObject();
	void RenderItems(int layer);
	
	void SetManaFatigue(float m);
	float GetManaFatigue();
	float GetMaxManaFatigue();
	void SetManaRegen(float r);
	float GetManaRegen();

	void DealDamage(int d, LevelManager * game, GameObject * go);

	void AddItem(Item * item, LevelManager * game);

	std::vector<Item *> * GetItems();

	void DamageDelt(LevelManager * game, GameObject * go);
	void UpdateProjectile(LevelManager * game, Projectile * p);
	void OnKill(LevelManager * game, GameObject * go);
	int GetDir();

	bool DownPressed();

	UseableItem * GetUseItem();

	void SetMaxJumps(int j);
	int GetMaxJumps();
	void SetMaxSpeed(float s);
	float GetMaxSpeed();
	void SetAcceleration(float a);
	float GetAcceleration();

	bool OverrideStatus(Status * s);

private:

	bool left = false, right = false, attack = false, attackLock = false, down = false;

	float maxSpeed = 7, acceleration = .6f, jumpPower = 11.5f, maxFatigue = 10, manaFatigue = 10, manaRegen = .08f;

	int dir = 1, shotDelay = 30, shot = 0, smokeDelay = 0, dash = 0, maxJumps = 1, jumps = 0;

	std::vector<Item *> * items;
	UseableItem * useItem;

};

#endif