// ANDER MARTINEZ 2014

#include <iostream>
#include "SDL.h"

#include "gb/core/input_hal.h"

using namespace std;

int main(int argc, char**argv){
	SDL_Window *window;
	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow(
        "InputHAL test",                   // window title
        SDL_WINDOWPOS_UNDEFINED,           // initial x position
        SDL_WINDOWPOS_UNDEFINED,           // initial y position
        640,                               // width, in pixels
        480,                               // height, in pixels
        SDL_WINDOW_OPENGL                  // flags - see below
	);

    bool quit = false;
	gamelad::InputHAL ih;
	while( !quit ){
		if(ih.is_pressed(ih.DOWN)){
			cout << "DOWN!" << endl;
		}
		if(ih.is_pressed(ih.UP)){
			cout << "UP!" << endl;
		}
		if(ih.is_pressed(ih.LEFT)){
			cout << "LEFT!" << endl;
		}
		if(ih.is_pressed(ih.RIGHT)){
			cout << "RIGHT!" << endl;
		}
		if(ih.is_pressed(ih.A)){
			cout << "A!" << endl;
		}
		if(ih.is_pressed(ih.B)){
			cout << "B!" << endl;
		}
		if(ih.is_pressed(ih.SELECT)){
			cout << "SELECT!" << endl;
		}
		if(ih.is_pressed(ih.START)){
			cout << "START!" << endl;
			quit = true;
		}
		SDL_Delay(200);
	}

	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
