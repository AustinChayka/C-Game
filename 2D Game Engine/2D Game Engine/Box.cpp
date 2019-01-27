#include "Box.h"

#include "Player.h"

Box::Box(float x, float y) : GameObject("assets/Box.png", x, y, 32, 32, 3) {

	collidable = true;

}

Box::~Box() {}

void Box::Update(LevelManager * game) {
	
	vY += .9f;

}

void Box::OnCollision(GameObject * go) {

	if(go->IsMoveable() && GetCollisionWall(go) != TOP) 
		go->SetVX(go->GetVX() / 1.75f);

}