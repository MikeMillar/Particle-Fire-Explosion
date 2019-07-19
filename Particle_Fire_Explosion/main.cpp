#include <iostream>
#include <SDL.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "Screen.h"
#include "Swarm.h"
#include "Particle.h"

using namespace std;


int main(int argc, char *argv[]) {
	srand(time(NULL));

	sf::Screen screen;

	if (screen.init() == false) {
		cout << "Error initializing SDL." << endl;
	}

	sf::Swarm swarm;
	
		
	while (true) { // Program Loop
		// Update particles
		

		// Draw particles
		int elapsed = SDL_GetTicks();

		swarm.update(elapsed);

		unsigned char red = (1 + sin(elapsed * 0.0002)) * 128;
		unsigned char green = (1 + sin(elapsed * 0.0001)) * 128;
		unsigned char blue = (1 + sin(elapsed * 0.0003)) * 128;

		const sf::Particle* const pParticles = swarm.getParticles();
		for (int i = 0; i < sf::Swarm::NPARTICLES; i++) {
			sf::Particle particle = pParticles[i];
			int x = (particle.m_x + 1) * (sf::Screen::SCREEN_WIDTH / 2);
			int y = (particle.m_y * (sf::Screen::SCREEN_WIDTH / 2)) + (sf::Screen::SCREEN_HEIGHT / 2);

			screen.setPixel(x, y, red, green, blue);
		}

		screen.boxBlur();

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