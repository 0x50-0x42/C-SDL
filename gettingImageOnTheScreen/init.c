#include<SDL2/SDL.h>
#include<stdbool.h>

extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;

bool init(SDL_Window** window, SDL_Surface** windowSurface) {

	// initialize SDL
	if(SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL could not be initialized! SDL_Error: %s\n", SDL_GetError());
		return false;
	}

	// create the window
	*window = SDL_CreateWindow("SDL tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	if(!*window) {
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		return false;
	}

	// get window surface
	*windowSurface = SDL_GetWindowSurface(*window); /* we want to show images inside of the
							 window and in order to do that we
							 need to get the image inside of the
							 window; so we call SDL_GetWindowSurface()
							 to grab the surface contained by the
							 window */

	return true;
}
