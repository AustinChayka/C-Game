#ifndef Camera_h
#define Camera_h

class GameObject;

class Camera {

public:

	Camera(float init_x, float init_y, float init_width, float init_height);
	~Camera();

	float GetX();
	float GetY();
	float GetScale();
	float GetWidth();
	float GetHeight();

	void SetPos(float newX, float newY);
	void ChangePos(float dx, float dy);
	void SetSize(float newScale);
	void ChangeSize(float deltaScale);
	void SetTarget(GameObject * go);
	void SetTarget(float newX, float newY);
	void SetSpeed(float newSpeed);

	void Update();

	static enum Mode {
		LOCKED = 0,
		POST_FRAMED = 1,
		STATIC = 2
	};


private:

	float x, y, width, height, scale, minScale = .1f, maxScale = 5, speed = .08f, targetX, targetY;
	int currentMode = 1;
	GameObject * target;

};

#endif