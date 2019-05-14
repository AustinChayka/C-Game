#include "StateManager.h"

#include "GameOverScreen.h"
#include "KeybindMenu.h"

LevelManager * levelManager = nullptr;
MenuState * mainMenu = nullptr;
MenuState * pauseMenu = nullptr;

StateManager::StateManager() : levelManager() {

	levelManager = new LevelManager();
	mainMenu = new MenuState();
	pauseMenu = new MenuState();
	gameOver = new GameOverScreen();
	controlsMenu = new KeybindMenu();
	
	levelManager->LoadLevel(0);

	activeState = 0;

}

StateManager::~StateManager() {}

void StateManager::Update() {

	if(!stateChanged && Game::inputManager->GetLastEvent()->type == SDL_KEYDOWN && 
		Game::inputManager->GetLastEvent()->key.keysym.sym == SDLK_ESCAPE) {
		if(activeState == 1) ChangeState(2);
		else if(activeState == 2) ChangeState(1);
		stateChanged = true;
	} else if(Game::inputManager->GetLastEvent()->type == SDL_KEYUP && 
		Game::inputManager->GetLastEvent()->key.keysym.sym == SDLK_ESCAPE) stateChanged = false;
	
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

		case 3:
			gameOver->Update(this);
			break;

		case 4:
			controlsMenu->Update(this);
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

		case 3:
			gameOver->Render();
			break;

		case 4:
			controlsMenu->Render();

		default:
			break;

	}

}

void StateManager::ChangeState(int n) {

	activeState = n;

}

LevelManager * StateManager::GetLevelManager() {

	return levelManager;

}

void StateManager::SetLevelManager(LevelManager * l) {

	levelManager = l;

}
