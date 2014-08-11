// ANDER MARTINEZ 2014

#include "SDL.h"
#include "gb/core/input_hal.h"


static Uint8* keys;
gamelad::InputHAL::InputHAL(void){
	keys = const_cast<Uint8*>(SDL_GetKeyboardState(NULL));
}

gamelad::InputHAL::~InputHAL(void){
	// Nothing to do.
}

#include <iostream>
bool gamelad::InputHAL::is_pressed(Key key){
	int sc; 
	SDL_PumpEvents();
	switch(key){
		case UP:
			sc = SDL_SCANCODE_UP;
		break;
		case DOWN:
			sc = SDL_SCANCODE_DOWN;
		break;
		case LEFT:
			sc = SDL_SCANCODE_LEFT;
		break;
		case RIGHT:
			sc = SDL_SCANCODE_RIGHT;
		break;
		case A:
			sc = SDL_SCANCODE_A;
		break;
		case B:
			sc = SDL_SCANCODE_S;
		break;
		case SELECT:
			sc = SDL_SCANCODE_SPACE;
		break;
		case START:
			sc = SDL_SCANCODE_RETURN;
		break;
		default:
		return false;
	}
	return keys[sc];
}