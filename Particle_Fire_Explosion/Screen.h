#ifndef SCREEN_H
#define SCREEN_H
#include <SDL.h>

namespace sf {

	class Screen {
	private:
		SDL_Window* m_window;
		SDL_Renderer* m_renderer;
		SDL_Texture* m_texture;
		Uint32* m_buffer;

	public:
		const static int SCREEN_WIDTH = 800;
		const static int SCREEN_HEIGHT = 600;

	public:
		Screen();
		bool init();
		bool processEvents();
		void close();
	};

}
#endif