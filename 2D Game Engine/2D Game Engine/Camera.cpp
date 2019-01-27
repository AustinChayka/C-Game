#include "Camera.h"

Camera::Camera(float init_x, float init_y, float init_width, float init_height) {

	x = init_x;
	y = init_y;
	width = init_width;
	height = init_height;

	scale = 1;

}

Camera::~Camera() {}

float Camera::GetX() {

	return x;

}

float Camera::GetY() {

	return y;

}

float Camera::GetScale() {

	return scale;

}

float Camera::GetWidth() {

	return width;

}

float Camera::GetHeight() {

	return height;

}

void Camera::SetPos(float newX, float newY) {

	x = newX;
	y = newY;

}

void Camera::ChangePos(float dx, float dy) {

	x += dx;
	y += dy;

}

void Camera::SetSize(float newScale) {

	if(newScale < minScale) scale = minScale;
	else if(newScale > maxScale) scale = maxScale;
	else scale = newScale;

}

void Camera::ChangeSize(float deltaScale) {

	if(scale + deltaScale < minScale) scale = minScale;
	else if(scale + deltaScale > maxScale) scale = maxScale;
	else scale += deltaScale;

}

void Camera::SetTarget(GameObject * go) {

	target = go;

}

void Camera::SetSpeed(float newSpeed) {

	speed = newSpeed;

}

void Camera::Update() {

	if(target == nullptr) return;

	int targetX = target->GetXCenter() - (width / 2) / scale,
		targetY = target->GetYCenter() - (height / 2) / scale;

	switch(currentMode) {

		case 0:
			x = targetX;
			y = targetY;
			break;

		case 1:
			x += (targetX - x) * speed;
			y += (targetY - y) * speed;
			break;

	}

}
