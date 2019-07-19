#include <iostream>
#include <SDL.h>
#include "Screen.h"

using namespace std;


int main(int argc, char *argv[]) {

	sf::Screen screen;

	if (screen.init() == false) {
		cout << "Error initializing SDL." << endl;
	}
	
	
	while (true) { // Program Loop
		// Update particles
		

		// Draw particles
		for (int y = 0; y < sf::Screen::SCREEN_HEIGHT; y++) {
			for (int x = 0; x < sf::Screen::SCREEN_WIDTH; x++) {
				screen.setPixel(x, y, 128, 0, 255);
			}
		}

		screen.setPixel(400, 300, 255, 255, 255);

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