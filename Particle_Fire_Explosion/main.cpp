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

	// Creates a 2D rendering context for window
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
	// Creates texture for rendering context
	SDL_Texture* texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);

	// Checks to see if renderer and texture loads, exits with error if not.
	if (renderer == NULL) {
		cout << "Could not create renderer. SDL Error: " << SDL_GetError() << endl;
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 3;
	}
	if (texture == NULL) {
		cout << "Could not create texture. SDL Error: " << SDL_GetError() << endl;
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 4;
	}

	Uint32* buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT]; // Allocate memory for all pixels in program

	memset(buffer, 0xFF, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32)); // Sets all pixel memory to white

	// Update screen information
	SDL_UpdateTexture(texture, NULL, buffer, SCREEN_WIDTH * sizeof(Uint32));
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, texture, NULL, NULL);
	SDL_RenderPresent(renderer);

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
	delete[] buffer;
	SDL_DestroyRenderer(renderer);
	SDL_DestroyTexture(texture);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return EXIT_SUCCESS;
}