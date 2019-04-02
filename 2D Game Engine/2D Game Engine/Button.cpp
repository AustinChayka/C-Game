#include "Button.h"

Button::Button(float init_x, float init_y, int img_width, int img_height, const char * buttonText, float init_scale) {

	texture = TextureManager::LoadTexture(Game::renderer, "assets/Other/Button.png");
	text = TextureManager::LoadText(Game::renderer, 24, {255, 255, 255}, buttonText);

	scale = init_scale;

	x = init_x;
	y = init_y;
	width = img_width * scale;
	height = img_height * scale;

	destRect.x = x + 6 * scale;
	destRect.y = y + 6 * scale;
	destRect.w = img_width * scale - 12 * scale;
	destRect.h = img_height * scale - 12 * scale;

	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = img_width;
	srcRect.h = img_height;

	tileSrcRect.x = 0;
	tileSrcRect.y = 0;
	tileSrcRect.w = 6;
	tileSrcRect.h = 6;
	tileDestRect.w = 6 * scale;
	tileDestRect.h = 6 * scale;

}

Button::~Button() {

	SDL_DestroyTexture(texture);
	SDL_DestroyTexture(text);

}

void Button::Update(StateManager * sm, MenuState * m) {

	lastPressed = pressed;

	if(MouseOver()) {
		SDL_SetTextureColorMod(text, 255, 255, 150);
		if(Game::event.button.button == 1 && Game::event.type == SDL_MOUSEBUTTONDOWN) {
			SDL_SetTextureColorMod(text, 150, 255, 150);
			pressed = true;
		} else {
			SDL_SetTextureColorMod(text, 255, 255, 150);
			pressed = false;
		}
	} else {
		SDL_SetTextureColorMod(text, 255, 255, 255);
	}

	if(IsHeld()) OnHold(sm, m);
	if(IsPressed()) OnPress(sm, m);
	if(IsReleased()) OnRelease(sm, m);
	
}

void Button::Render() {

	for(int j = 0; j < (int)(height / (6 * scale)); j++) for(int i = 0; i < (int)(width / (6 * scale)); i++) {
		tileDestRect.x = x + 6 * i * scale;
		tileDestRect.y = y + 6 * j * scale;
		if(j == 0 && i == 0) { tileSrcRect.x = 0; tileSrcRect.y = 0; }
		else if(j == 0 && i == (int)(width / (6 * scale)) - 1) { tileSrcRect.x = 12; tileSrcRect.y = 0; }
		else if(j == (int)(height / (6 * scale)) - 1 && i == 0) { tileSrcRect.x = 0; tileSrcRect.y = 12; }
		else if(j == (int)(height / (6 * scale)) - 1 && i == (int)(width / (6 * scale)) - 1) { tileSrcRect.x = 12; tileSrcRect.y = 12; }
		else if(j == 0) { tileSrcRect.x = 6; tileSrcRect.y = 0; }
		else if(j == (int)(height / (6 * scale)) - 1) { tileSrcRect.x = 6; tileSrcRect.y = 12; }
		else if(i == 0) { tileSrcRect.x = 0; tileSrcRect.y = 6; }
		else if(i == (int)(width / (6 * scale)) - 1) { tileSrcRect.x = 12; tileSrcRect.y = 6; }
		else { tileSrcRect.x = 6; tileSrcRect.y = 6; }
		SDL_RenderCopy(Game::renderer, texture, &tileSrcRect, &tileDestRect);
	}
	SDL_RenderCopy(Game::renderer, text, &srcRect, &destRect);
	
}

bool Button::IsHeld() {

	return pressed && lastPressed;

}

bool Button::IsPressed() {

	return pressed && !lastPressed;

}

bool Button::IsReleased() {

	return !pressed && lastPressed;

}

bool Button::MouseOver() {

	int mouse_x = Game::event.motion.x, mouse_y = Game::event.motion.y;

	return mouse_x > x && mouse_x < x + width
		&& mouse_y > y && mouse_y < y + height;

}
