#include "Window.h"

GROUND ground = { 80, SCREEN_HEIGHT - 730, 350, 700,
	{
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 1, 1, 1, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 }
	} 
};


Window::Window(const string& title, unsigned short width, unsigned short height) :
	m_title(title), m_width(width), m_height(height)
{
	m_window = nullptr;
	m_renderer = nullptr;
	m_texture = nullptr;

	m_isClosed = !Init();
}


Window::~Window()
{
	Destroy();
}

bool Window::Init()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		cerr << "Initialization error: " << SDL_GetError() << endl;
		return false;
	}

	if (IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG)
	{
		cerr << "Faled to initialize SDL Image" << endl;
		return false;
	}

	m_window = SDL_CreateWindow(m_title.c_str(),
								SDL_WINDOWPOS_CENTERED,
								SDL_WINDOWPOS_CENTERED, 
								m_width, 
								m_height, 
								SDL_WINDOW_SHOWN);

	if (m_window == nullptr)
	{
		cerr << "Window Creation error: " << SDL_GetError() << endl;
		return false;
	}

	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if (m_renderer == nullptr)
	{
		cerr << "Renderer creation error: " << SDL_GetError() << endl;
		return false;
	}

	SDL_Surface* surface = IMG_Load("../Tetris/Images/Tile.png");

	if (!surface)
	{
		cerr << "Failed to load the image" << endl;
		return false;
	}

	m_texture = SDL_CreateTextureFromSurface(m_renderer, surface);

	if (!m_texture)
	{
		cerr << "Failed to create the texture from surface" << endl;
		return false;
	}

	SDL_FreeSurface(surface);

	return true;
}

void Window::Update()
{
	UpdateGround();
}

void Window::Render()
{
	SDL_SetRenderDrawColor(m_renderer, 120, 40, 40, 255);
	SDL_RenderClear(m_renderer);

	RenderGround();

	SDL_RenderPresent(m_renderer);
}

void Window::Destroy()
{
	Cleanup(m_window, m_renderer, m_texture);
	IMG_Quit();
	SDL_Quit();
}

void Window::PollEvents()
{
	SDL_Event event;

	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
		{
			m_isClosed = true;
			break;
		}

		case SDL_KEYDOWN:
		{
			ProcessKeys(event.key);
			break;
		}
		default:
			break;
		}
	}


}

void Window::ProcessKeys(const SDL_KeyboardEvent& kbEvent)
{
	switch (kbEvent.keysym.sym)
	{
	case SDLK_LEFT:
	case SDLK_a:
	{
		cout << "Left Pressed!" << endl;
		break;
	}
	case SDLK_RIGHT:
	case SDLK_d:
	{
		cout << "Right Pressed!" << endl;
		break;
	}
	case SDLK_DOWN:
	case SDLK_s:
	{
		cout << "Down Pressed!" << endl;
		break;
	}
	case SDLK_UP:
	case SDLK_w:
	{
		cout << "Down Pressed!" << endl;
		break;
	}
	case SDLK_ESCAPE:
	{
		m_isClosed = true;
		cout << "Esc Pressed!" << endl;
		break;
	}

	default:
		break;
	}
}

void Window::UpdateGround()
{
	
}

void Window::RenderGround()
{
	SDL_Rect playGround;

	playGround.w = ground.width;
	playGround.h = ground.height;
	playGround.x = ground.posX;
	playGround.y = ground.posY;
	SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
	SDL_RenderFillRect(m_renderer, &playGround);
	
	
	int pieceSize = ground.width / 10;
	for (size_t i = 0; i < 20; ++i)
	{
		for (size_t j = 0; j < 10; ++j)
		{
			if (ground.active[i][j])
			{
				SDL_Rect piece = { ground.posX + (pieceSize * j), ground.posY + (pieceSize * i), pieceSize, pieceSize };
				SDL_RenderCopy(m_renderer, m_texture, nullptr, &piece);
			}
		}
	}
}