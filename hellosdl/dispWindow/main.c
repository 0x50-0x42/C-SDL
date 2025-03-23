/******
 * Program: main.c
 * Description: getting a windows to pop up
 * ******/

#include<SDL2/SDL.h>
#include<stdio.h>
#include<stdbool.h>

/* width and height of the screen */
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char *argv[]) {

	// the window to render to
	SDL_Window* window = NULL;

	// the surface contained by the window
	SDL_Surface *screenSurface = NULL; /* an SDL surface is just a 2D image which can be
					      loaded from a file or it can be an image that
					      we see inside of the window */

	// initialize SDL
	if(SDL_Init(SDL_INIT_VIDEO) < 0) { /* to be able call any SDL function, we must first
					      initialize SDL, the SDL_INIT_VIDEO flag is passed
					      for the video subsystem;
					      when there's any error, SDL_Init() returns -1 */

		printf("SDL couldn't initialize! %s\n", SDL_GetError()); /* SDL_GetError() lets
									    us know if any errors
									    happened inside of
									    any SDL function */
	}

	else {
		// create the window if there were no errors
		window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN); /* after successful initialization of SDL,
																			       we will create the window using the
																			       function SDL_CreateWindow();
																			       the first argument is the title of the
																			       window ("SDL Tutorial"), the second and
																			       the third arguments are the x and y
																			       positions in which the window is
																			       created (in this case, they are not
																			       defined), the next two arguments define
																			       the width and height of the window and
																			       the last argument is some creation
																			       flags. `SDL_WINDOW_SHOWN` makes sure
																			       that the window is shown when it is
																			       created;
																			       SDL_CreateWindow() returns NULL if
																			       there is any error; */

		if(window == NULL) {
			printf("Window couldn't be created! SDL Error: %s\n", SDL_GetError());
		}

		else {
			// get the window surface
			screenSurface = SDL_GetWindowSurface(window); /* we want to get the
									 window's surface so we
									 can draw to it;
									 SDL_GetWindowSurface()
									 does exactly that; */


			// fill the surface white
			SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));

			/* !! Just because we have drawn something to the screen
			 * doesn't mean we'll see it; to see it, we will need to update
			 * the window so it shows everything that we drew !!
			 * A call to SDL_UpdateWindowSurface() will do this */

			// update the surface
			SDL_UpdateWindowSurface(window);

			SDL_Event e;
			bool quit = false;

			/* after all this, we are going to see a window flash for a second
			 * and then close; we want that window to stay and not disappear
			 * and for that we are using this while loop */
			while(!quit) {
				while(SDL_PollEvent(&e)) {
					if(e.type == SDL_QUIT)
						quit = true;
				}
			}
		}

	}

	// destroy the window
	SDL_DestroyWindow(window);


	// quit SDL subsystems
	SDL_Quit();

	return 0;
}
