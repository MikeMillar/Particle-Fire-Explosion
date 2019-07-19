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
		// Check for messages/events


		// Listens for quit event, exits loop if it finds it.
		if (screen.processEvents() == false) {
			break;
		}
	}

	screen.close();
	return EXIT_SUCCESS;
}