#include <iostream>
#include <SDL.h>

using namespace std;


int main(int argc, char *argv[]) {
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		cout << "SDL could not initialize! SDL Error: " << SDL_GetError() << endl;
	}
	cout << "SDL Initialization succeeded." << endl;


	SDL_Quit();
	return EXIT_SUCCESS;
}