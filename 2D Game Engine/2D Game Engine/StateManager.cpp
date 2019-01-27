#include "StateManager.h"

LevelManager * levelManager = nullptr;
MenuState * mainMenu = nullptr;
MenuState * pauseMenu = nullptr;

StateManager::StateManager() : levelManager() {

	levelManager = new LevelManager();
	
	levelManager->LoadLevel(0);

	activeState = 0;

}

StateManager::~StateManager() {}

void StateManager::Update() {

	if(!stateChanged && Game::event.type == SDL_KEYDOWN && Game::event.key.keysym.sym == SDLK_ESCAPE) {
		if(activeState == 0) ChangeState(1);
		else ChangeState(0);
		stateChanged = true;
	} else if(Game::event.type == SDL_KEYUP && Game::event.key.keysym.sym == SDLK_ESCAPE) stateChanged = false;
	
	switch(activeState) {

		case 0:
			mainMenu->Update(this);
			break;

		case 1:
			levelManager->Update(this);
			break;

		case 2:
			pauseMenu->Update(this);
			break;

		default:
			break;
			
	}

}

void StateManager::Render() {

	switch(activeState) {

		case 0:
			mainMenu->Render();
			break;

		case 1:
			levelManager->Render();
			break;

		case 2:
			pauseMenu->Render();
			break;

		default:
			break;

	}

}

void StateManager::ChangeState(int n) {

	activeState = n;

}
