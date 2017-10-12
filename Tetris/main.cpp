#include "Window.h"


void LogSDLError(ostream &ostream, const string &msg)
{
	ostream << msg << " error: " << SDL_GetError() << endl;
}

int main(int argc, char* argv[])
{

	Window window = Window("Tetris", SCREEN_WIDTH, SCREEN_HEIGHT);

	while (!window.isClosed())
	{
		window.PollEvents();
		window.Render();
	}

	/*SDL_Event events;
	bool exit = false;
	SDL_Window *window = nullptr;

	//Initialize SDL, in case of failure, write the error in the console.
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		LogSDLError(cout, "Initializing SDL");
		return 1;
	}

	//Create the window.
	window = SDL_CreateWindow("Tetris", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 800, SDL_WINDOW_SHOWN);

	//In case of failure, write the error in the console.
	if (window == nullptr)
	{
		LogSDLError(cout, "CreateWindow");
		SDL_Quit();
		return 1;
	}

	SDL_Surface* screenSurface = SDL_GetWindowSurface(window);
	SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0x00, 0x00, 0x00) );

	SDL_UpdateWindowSurface(window);

	while(!exit)
	{ 
		
	}

	SDL_Delay(2000);

	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if (renderer == nullptr)
	{
		LogSDLError(cout, "CreateRenderer");
		SDL_Quit();
		return 1;
	}


	Cleanup(window, renderer);

	SDL_Quit();*/

	return 0;
}