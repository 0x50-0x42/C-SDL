/*
 * the SDL_LoadBMP() takes in the path of a bmp file and returns the loaded surface;
 * on failure, it returns NULL;
 */

#include<SDL2/SDL.h>
#include<stdbool.h>

extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;

bool loadMedia(SDL_Surface** imageSurface) {

	// load the image
	*imageSurface = SDL_LoadBMP("images/xout.bmp");
	if(!*imageSurface) {
		printf("Unable to load image! SDL_Error: %s\n", SDL_GetError());
		return false;
	}

	return true;
}
