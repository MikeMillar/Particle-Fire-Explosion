#include <iostream>
#include <SDL.h>

using namespace std;


int main(int argc, char *argv[]) {

	// Set const screen dimensions
	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 600;

	// Check if SDL initialized properly. SDL_Init will return < 0 if it failed.
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		cout << "SDL could not initialize! SDL Error: " << SDL_GetError() << endl;
		return 1;
	}
	// Sets a pointer to window, and creates a window (Title, window xpos, window ypos, screen width, screen height, window param(see ref))
	SDL_Window* window = SDL_CreateWindow("Particle Fire Explosion", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	// Checks to make sure window loaded properly, returns error if not
	if (window == NULL) {
		cout << "Could no create window. SDL Error: " << SDL_GetError() << endl;
		SDL_Quit();
		return 2;
	}

	// Sets loop param to false
	bool quit = false;
	// Event listener
	SDL_Event event;
	// Program Loop
	while (!quit) {
		// Update particles
		// Draw particles
		// Check for messages/events


		// Listens for quit event, exits loop if it finds it.
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				quit = true;
			}
		}
	}

	// Destroys window when program is ending, and exits program
	SDL_DestroyWindow(window);
	SDL_Quit();
	return EXIT_SUCCESS;
}