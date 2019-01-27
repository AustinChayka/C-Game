#include "TestBlocker.h"

TestBlocker::TestBlocker(float x, float y) : GameObject("assets/Test.png", x, y, 200, 5, 3) { 
	collidable = true;  
	moveable = false;
}

TestBlocker::~TestBlocker() {}

void TestBlocker::Update(LevelManager * game) {}
