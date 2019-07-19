#include <iostream>
#include <SDL.h>
#include <math.h>
#include "Screen.h"

using namespace std;


int main(int argc, char *argv[]) {

	sf::Screen screen;

	if (screen.init() == false) {
		cout << "Error initializing SDL." << endl;
	}
	
	int max = 0;
	int min = 255;
	
	while (true) { // Program Loop
		// Update particles
		

		// Draw particles
		int elapsed = SDL_GetTicks();
		unsigned char red = (1 + sin(elapsed * 0.0002)) * 128;
		unsigned char green = (1 + sin(elapsed*0.0001)) * 128;
		unsigned char blue = (1 + sin(elapsed * 0.0003)) * 128;

		for (int y = 0; y < sf::Screen::SCREEN_HEIGHT; y++) {
			for (int x = 0; x < sf::Screen::SCREEN_WIDTH; x++) {
				screen.setPixel(x, y, red, green, blue);
			}
		}


		// Draw the screen
		screen.update();

		// Check for messages/events
		// Listens for quit event, exits loop if it finds it.
		if (screen.processEvents() == false) {
			break;
		}
	}
	
	screen.close();
	return EXIT_SUCCESS;
}