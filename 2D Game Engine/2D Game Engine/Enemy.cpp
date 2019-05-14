#include "Enemy.h"

#include <typeinfo>
#include "GoldDrop.h"
#include "Player.h"

Enemy::Enemy(const char * filepath, float x, float y, int width, int height, float scale, int h) : 
	GameObject(filepath, x, y, width, height, scale) {

	damageable = true;
	health = maxHealth = h;

}

Enemy::~Enemy() {

	for(int i = 0; i < statuses.size(); i++) delete statuses.at(i);
	statuses.clear();

}

void Enemy::Update(LevelManager * game) {

	for(int i = 0; i < statuses.size(); i++) {

		statuses.at(i)->Update(this, game);

		if(!statuses.at(i)->IsActive()) {
			delete statuses.at(i);
			statuses.erase(statuses.begin() + i);
			i--;
		}

	}

}

void Enemy::RenderObject() {

	GameObject::RenderObject();

	for(int i = 0; i < statuses.size(); i++) statuses.at(i)->Render(i);

}

void Enemy::DealDamage(int d, LevelManager * game, GameObject * go) {

	GameObject::DealDamage(d, game, go);

	if(go != nullptr && dynamic_cast<Enemy *>(go) != nullptr) target = go;

}

void Enemy::OnDeath(LevelManager * game, GameObject * go) {

	GameObject::OnDeath(game, go);
	for(int i = 0; i < rand() % 3 + 1; i++) {
		GameObject * gd = new GoldDrop(GetXCenter(), GetYCenter(), rand() % 3 + 1);
		gd->SetVX(rand() % 6 - 3);
		gd->SetVY(rand() % 6);
		game->AddObject(gd);
	}

}

void Enemy::AddStatus(Status * s) {

	if(OverrideStatus(s)) return;

	for(auto stat : statuses) if(typeid(*stat).name() == typeid(*s).name()) {

		stat->SetIncrement(stat->GetIncrement() + s->GetIncrement());

		delete s;

		return;

	}

	s->OnApply(this);
	statuses.push_back(s);

}

bool Enemy::OverrideStatus(Status * s) {

	return false;

}
