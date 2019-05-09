#ifndef Game_h
#define Game_h

#include "SDL.h"
#include <iostream>
#include "SDL_image.h"
#include "StateManager.h"
#include "Camera.h"
#include "GUI.h"
#include "InputManager.h"

class GameObject;
class StateManager;
class Camera;
class GUI;
class InputManager;

class Game {

public:

	Game(const char * title, int xPos, int yPos, int width, int height, bool fullscreen);
	~Game();
	
	void HandleEvents();
	void Update();
	void Render();
	void Clean();
	
	static SDL_Renderer * renderer;

	static InputManager * inputManager;
	static SDL_Event event;

	static Camera * camera;

	static int width, height;

	static GUI * gui;

	static bool running;

	SDL_Window * GetWindow();
	
private:
	
	SDL_Window * window;

	StateManager * stateManager;
				
};

#endif

