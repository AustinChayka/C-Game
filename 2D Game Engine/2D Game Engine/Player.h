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

	void DamageDelt(LevelManager * game, GameObject * go, bool crit);
	void UpdateProjectile(LevelManager * game, Projectile * p);
	void OnKill(LevelManager * game, GameObject * go);
	int GetDir();

	UseableItem * GetUseItem();

	void SetMaxJumps(int j);
	int GetMaxJumps();
	void SetMaxSpeed(float s);
	float GetMaxSpeed();
	void SetAcceleration(float a);
	float GetAcceleration();
	void SetShotDelay(int d);
	int GetShotDelay();
	void SetShotCost(float c);
	float GetShotCost();

	bool OverrideStatus(Status * s);

	int GetCritChance();
	float GetCritValue();
	void SetCritChance(int c);
	void SetCritValue(float v);
	int GetLuck();
	void SetLuck(int l);

	int GetGold();
	void AddGold(int g);
	void SetGold(int g);

private:

	bool attackLock = false;

	float maxSpeed = 7, acceleration = .6f, jumpPower = 11.5f, maxFatigue = 10, manaFatigue = 10, manaRegen = .08f, 
		shotCost = 1, critMultiplier = 2.0f;

	int dir = 1, shotDelay = 30, shot = 0, smokeDelay = 0, dash = 0, maxJumps = 1, jumps = 0, critChance = 10, luck = 50,
		gold = 0;

	std::vector<Item *> * items;
	UseableItem * useItem;

};

#endif