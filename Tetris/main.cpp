#include "Window.h"

const int FPS = 1000 / 60;


void LogSDLError(ostream &ostream, const string &msg)
{
	ostream << msg << " error: " << SDL_GetError() << endl;
}

int main(int argc, char* argv[])
{

	Window window = Window("Tetris", SCREEN_WIDTH, SCREEN_HEIGHT);

	Uint32 start_time = 0;

	Uint32 counter = 0;
	Uint32 deltaTime = 0;

	while (!window.isClosed())
	{
		start_time = SDL_GetTicks();

		if (FPS > (SDL_GetTicks() - start_time))
		{
			SDL_Delay(FPS);
		}

		deltaTime = (SDL_GetTicks() - start_time);

		window.PollEvents();
		window.Update(deltaTime);
		window.Render();
	}

	return 0;
}
