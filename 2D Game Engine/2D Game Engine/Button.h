#ifndef Button_h
#define Button_h

#include "SDL.h"
#include "Game.h"

class MenuState;

class Button {

public:

	Button(float init_x, float init_y, int init_width, int init_height, const char * buttonText, float scale);

	~Button();

	void Update(StateManager * sm, MenuState * m);

	void Render();

	bool IsHeld();
	bool IsPressed();
	bool IsReleased();

	virtual void OnHold(StateManager * sm, MenuState * m) = 0;
	virtual void OnPress(StateManager * sm, MenuState * m) = 0;
	virtual void OnRelease(StateManager * sm, MenuState * m) = 0;

private:

	SDL_Texture * texture;
	SDL_Texture * text;

	SDL_Rect srcRect, destRect, tileSrcRect, tileDestRect;

	bool MouseOver();

	float x, y, scale;
	int width, height;

	bool pressed, lastPressed;

};

#endif