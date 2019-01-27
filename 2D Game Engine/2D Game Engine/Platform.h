#ifndef Platform_h
#define Platform_h

#include "GameObject.h"

class Platform : public GameObject {

public:

	Platform(float x, float y, int segments_width);

	~Platform();

	void RenderObject();
	void Update(LevelManager * game);

private:

	int segments;

};

#endif