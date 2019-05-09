#include "InputManager.h"

#include <iostream>
#include <vector>

InputManager::InputManager() {
	
	commands[0] = SDLK_a;
	commands[1] = SDLK_d;
	commands[2] = SDLK_w;
	commands[3] = SDLK_s;
	commands[4] = SDLK_SPACE;
	commands[5] = SDLK_LCTRL;
	commands[6] = SDLK_e;
	commands[7] = SDLK_q;
	commands[8] = SDLK_LSHIFT;

	for(int i = 0; i < numCommands; i++) {
		commandTriggers[i][0] = false;
		commandTriggers[i][1] = false;
	}

	FlashSaveControlLayout();

}

InputManager::~InputManager() {}

void InputManager::Update(SDL_Event * event) {

	lastEvent = event;

	for(int i = 0; i < numCommands; i++) {
		commandTriggers[i][1] = commandTriggers[i][0];
	}

	if(event->type == SDL_KEYUP) {
		for(int i = 0; i < numCommands; i++) {
			if(event->key.keysym.sym == commands[i])
				commandTriggers[i][0] = false;
		}
	} else if(event->type == SDL_KEYDOWN) {
		for(int i = 0; i < numCommands; i++) {
			if(event->key.keysym.sym == commands[i])
				commandTriggers[i][0] = true;
		}
	}

}

bool InputManager::IsPressed(int k) {
	
	return commandTriggers[k][0] && !commandTriggers[k][1];

	return false;

}

bool InputManager::IsHeld(int k) {

	return commandTriggers[k][0] && commandTriggers[k][1];

	return false;

}

bool InputManager::IsReleased(int k) {

	return !commandTriggers[k][0] && commandTriggers[k][1];

	return false;

}

bool InputManager::IsDown(int k) {

	return commandTriggers[k][0];

	return false;

}

void InputManager::RebindCommand(int command, int key) {

	commands[command] = key;

}

void InputManager::FlashSaveControlLayout() {

	for(int i = 0; i < numCommands; i++) commandsFlash[i] = commands[i];

}

void InputManager::RandomizeCommands() {

	int n;
	std::vector<int> tempCommandKeys;
	for(int key : commands) tempCommandKeys.push_back(key);
	
	for(int i = 0; i < numCommands; i++) {
		n = rand() % tempCommandKeys.size();
		commands[i] = tempCommandKeys.at(n);
		tempCommandKeys.erase(tempCommandKeys.begin() + n);
	}

}

void InputManager::ResetCommands() {

	for(int i = 0; i < numCommands; i++) commands[i] = commandsFlash[i];

}

SDL_Event * InputManager::GetLastEvent() {

	return lastEvent;

}
