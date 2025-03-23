/******
 * Program: main.c
 * Description: event driven programming
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

	if(!init(&window, &screenSurface))
		puts("\naborting...");

	else {
		if(!loadMedia(&helloWorld))
			puts("aboring...");
		else {
			// apply the image
			SDL_BlitSurface(helloWorld, NULL, screenSurface, NULL);

			// update the surface (ofcourse)
			SDL_UpdateWindowSurface(window);

			// event handling going on here
			SDL_Event e;
			bool quit = false;
			/* SDL_Event is a union;
			 * an SDL event is something like a keypress, mouse motion,
			 * joy button press, etc; */

			while(!quit) { /* game loop, keeps on looping the application while
					  the user has not quit */
				while(SDL_PollEvent(&e)) { /* event loop, this loop
							      keeps processing the the event
							      queue until it is empty;
							      when we press a key, move the mouse,
							      or touch a touch screen, we put
							      events into the event queue;
							      the event queue will then store
							      them in the order the events
							      occurred waiting for us to process
							      them */
					/* when we want to find out what events occurred so we
					 * can process them, we poll the event queue to get
					 * the most recent event by calling the SDL_PollEvent()
					 * function;
					 *
					 * what this function does is take the most recent event
					 * from the event queue and puts the data from the
					 * event into the SDL_Event we passed into the function;
					 *
					 * SDL_PollEvent() will keep taking events off the queue
					 * until it's empty; when the queue is empty,
					 * SDL_PollEvent() will return 0;
					 *
					 * so this exactly what the condition in the event loop
					 * does is it keep polling events off the event queue
					 * until it's empty */

					if(e.type == SDL_QUIT) /* if an event from the queue is
								  an SDL_QUIT event (which is the
								  event when the user Xs out the
								  window), we set the quit flag
								  to true so that we can exit the
								  application; */
						quit = true;
				}
			}
		}
	}

	_close(window, helloWorld);

	return 0;
}
