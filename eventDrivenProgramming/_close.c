#include<SDL2/SDL.h>
#include<stdbool.h>

void _close(SDL_Window* window, SDL_Surface* imgSurface) {

	// deallocate the surface
	SDL_FreeSurface(imgSurface);
	imgSurface = NULL;

	// destroy window
	SDL_DestroyWindow(window);
	window = NULL;

	// quit the SDL subsystems
	SDL_Quit();
}
