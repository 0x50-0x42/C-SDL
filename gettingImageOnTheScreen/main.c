/******
 * Program: main.c
 * Description: getting an image on the screen
 * ******/

#include<SDL2/SDL.h>
#include<stdio.h>
#include<stdbool.h>

const int SCREEN_WIDTH = 320;
const int SCREEN_HEIGHT = 240;

// starts up SDL and creates window
bool init(SDL_Window**, SDL_Surface**);

// loads media
bool loadMedia(SDL_Surface**);

// frees media and shuts down SDL
void _close(SDL_Window*, SDL_Surface*);

int main(int argc, char *argv[]) {

	// the window to render to
	SDL_Window *window = NULL;

	// the surface contained by the window
	SDL_Surface *screenSurface = NULL;

	// the image we will load and show on the screen
	SDL_Surface *helloWorld = NULL;

	/* an SDL surface is just an 'image data type' that contains the pixels
	 * of an image along with all data needed to render it; */

	/* why use pointers:
	 * a) dynamic memory allocation;
	 * b) avoiding redundancy; */

	if(!init(&window, &screenSurface))
		puts("\naborting...");

	else {
		if(!loadMedia(&helloWorld))
			puts("aboring...");
		else {
			// apply the image
			SDL_BlitSurface(helloWorld, NULL, screenSurface, NULL);
			/* if we could load the image successfully, then we
			 * blit the loaded surface onto the screen surface
			 * using SDL_BlitSurface();
			 * what blitting does is that it takes a source surface and
			 * stamps a copy of it onto the destination surface;
			 *
			 * the first argument in SDL_BlitSurface() is the source surface (here
			 * it's the surface where the image is loaded) and the third argument 
			 * is the destination */

			// update the surface (ofcourse)
			SDL_UpdateWindowSurface(window);
			/* when we draw to the screen, we are not usually drawing to the
			 * image on the screen that we see;
			 * most rendering systems are double buffered;
			 * these two buffers are the front buffer and the back buffer;
			 *
			 * when we make draw calls like SDL_BlitSurface(), we render to
			 * the back buffer, what we see on the screen is the front buffer;
			 *
			 * most frames require drawing multiple objects to the screen; if
			 * we only had a front buffer, we would be able to see the frame
			 * as things being drawn to it which means that we would see unfinished
			 * frames;
			 * 
			 * so a better way to hide this is to use two buffers where we draw
			 * everything to the back buffer first and once we are done, we swap the
			 * back buffer and the front buffer so now the user can see the finished
			 * frame; */

			SDL_Event e;
			bool quit = false;

			while(!quit) {
				while(SDL_PollEvent(&e)) {
					if(e.type == SDL_QUIT)
						quit = true;
				}
			}
		}
	}

	_close(window, helloWorld);

	return 0;
}
