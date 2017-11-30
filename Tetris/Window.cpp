#include "Window.h"
#include <time.h>

/*
    Background structure for the game.
*/
GROUND ground =
{ 80, SCREEN_HEIGHT - 730, 350, 700,
    {
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 1, 1, 1, 0, 0, 0, 0, 1, 1, 1 }
    }
};

char shapes[SHAPE_NUM][SHAPE_STATES][SHAPE_SIZE] =
{
  //SHAPE L (0)
  {
      {
          0, 0, 0, 0, 0,
          0, 1, 0, 0, 0,
          0, 1, 0, 0, 0,
          0, 1, 1, 0, 0,
          0, 0, 0, 0, 0
      },
      {
          0, 0, 0, 0, 0,
          0, 1, 1, 1, 0,
          0, 1, 0, 0, 0,
          0, 0, 0, 0, 0,
          0, 0, 0, 0, 0
      },
      {
          0, 0, 0, 0, 0,
          0, 0, 1, 1, 0,
          0, 0, 0, 1, 0,
          0, 0, 0, 1, 0,
          0, 0, 0, 0, 0
      },
      {
          0, 0, 0, 0, 0,
          0, 0, 0, 0, 0,
          0, 0, 0, 1, 0,
          0, 1, 1, 1, 0,
          0, 0, 0, 0, 0
      }
  },
  //SHAPE J (1)
  {
      {
          0, 0, 0, 0, 0,
          0, 0, 0, 1, 0,
          0, 0, 0, 1, 0,
          0, 0, 1, 1, 0,
          0, 0, 0, 0, 0
      },
      {
          0, 0, 0, 0, 0,
          0, 0, 0, 0, 0,
          0, 1, 0, 0, 0,
          0, 1, 1, 1, 0,
          0, 0, 0, 0, 0
      },
      {
          0, 0, 0, 0, 0,
          0, 1, 1, 0, 0,
          0, 1, 0, 0, 0,
          0, 1, 0, 0, 0,
          0, 0, 0, 0, 0
      },
      {
          0, 0, 0, 0, 0,
          0, 1, 1, 1, 0,
          0, 0, 0, 1, 0,
          0, 0, 0, 0, 0,
          0, 0, 0, 0, 0
      }
  },
  //SHAPE T (2)
  {
      {
          0, 0, 0, 0, 0,
          0, 0, 0, 0, 0,
          0, 1, 1, 1, 0,
          0, 0, 1, 0, 0,
          0, 0, 0, 0, 0
      },
      {
          0, 0, 0, 0, 0,
          0, 0, 1, 0, 0,
          0, 1, 1, 0, 0,
          0, 0, 1, 0, 0,
          0, 0, 0, 0, 0
      },
      {
          0, 0, 0, 0, 0,
          0, 0, 1, 0, 0,
          0, 1, 1, 1, 0,
          0, 0, 0, 0, 0,
          0, 0, 0, 0, 0
      },
      {
          0, 0, 0, 0, 0,
          0, 0, 1, 0, 0,
          0, 0, 1, 1, 0,
          0, 0, 1, 0, 0,
          0, 0, 0, 0, 0
      }
  },
  //SHAPE S (3)
  {
      {
          0, 0, 0, 0, 0,
          0, 1, 1, 0, 0,
          1, 1, 0, 0, 0,
          0, 0, 0, 0, 0,
          0, 0, 0, 0, 0
      },
      {
          0, 0, 1, 0, 0,
          0, 0, 1, 1, 0,
          0, 0, 0, 1, 0,
          0, 0, 0, 0, 0,
          0, 0, 0, 0, 0
      },
      {
          0, 0, 0, 0, 0,
          0, 1, 1, 0, 0,
          1, 1, 0, 0, 0,
          0, 0, 0, 0, 0,
          0, 0, 0, 0, 0
      },
      {
          0, 0, 1, 0, 0,
          0, 0, 1, 1, 0,
          0, 0, 0, 1, 0,
          0, 0, 0, 0, 0,
          0, 0, 0, 0, 0
      }
  },
  //SHAPE Z (4)
  {
      {
          0, 0, 0, 0, 0,
          0, 0, 1, 1, 0,
          0, 0, 0, 1, 1,
          0, 0, 0, 0, 0,
          0, 0, 0, 0, 0
      },
      {
          0, 0, 1, 0, 0,
          0, 1, 1, 0, 0,
          0, 1, 0, 0, 0,
          0, 0, 0, 0, 0,
          0, 0, 0, 0, 0
      },
      {
          0, 0, 0, 0, 0,
          0, 0, 1, 1, 0,
          0, 0, 0, 1, 1,
          0, 0, 0, 0, 0,
          0, 0, 0, 0, 0
      },
      {
          0, 0, 1, 0, 0,
          0, 1, 1, 0, 0,
          0, 1, 0, 0, 0,
          0, 0, 0, 0, 0,
          0, 0, 0, 0, 0
      }
  },
  //SHAPE O (5)
  {
      {
          0, 0, 0, 0, 0,
          0, 1, 1, 0, 0,
          0, 1, 1, 0, 0,
          0, 0, 0, 0, 0,
          0, 0, 0, 0, 0
      },
      {
          0, 0, 0, 0, 0,
          0, 1, 1, 0, 0,
          0, 1, 1, 0, 0,
          0, 0, 0, 0, 0,
          0, 0, 0, 0, 0
      },
      {
          0, 0, 0, 0, 0,
          0, 1, 1, 0, 0,
          0, 1, 1, 0, 0,
          0, 0, 0, 0, 0,
          0, 0, 0, 0, 0
      },
      {
          0, 0, 0, 0, 0,
          0, 1, 1, 0, 0,
          0, 1, 1, 0, 0,
          0, 0, 0, 0, 0,
          0, 0, 0, 0, 0
      }
  },
  //SHAPE I (6)
  {
      {
          0, 0, 0, 0, 0,
          0, 0, 0, 0, 0,
          1, 1, 1, 1, 0,
          0, 0, 0, 0, 0,
          0, 0, 0, 0, 0
      },
      {
          0, 0, 1, 0, 0,
          0, 0, 1, 0, 0,
          0, 0, 1, 0, 0,
          0, 0, 1, 0, 0,
          0, 0, 0, 0, 0
      },
      {
          0, 0, 0, 0, 0,
          0, 0, 0, 0, 0,
          1, 1, 1, 1, 0,
          0, 0, 0, 0, 0,
          0, 0, 0, 0, 0
      },
      {
          0, 0, 1, 0, 0,
          0, 0, 1, 0, 0,
          0, 0, 1, 0, 0,
          0, 0, 1, 0, 0,
          0, 0, 0, 0, 0
      }
  }
};

/*
char shapeL[SHAPE_STATES][SHAPE_SIZE] =
{
    {
        0, 0, 0, 0, 0,
        0, 1, 0, 0, 0,
        0, 1, 0, 0, 0,
        0, 1, 1, 0, 0,
        0, 0, 0, 0, 0
    },
    {
        0, 0, 0, 0, 0,
        0, 1, 1, 1, 0,
        0, 1, 0, 0, 0,
        0, 0, 0, 0, 0,
        0, 0, 0, 0, 0
    },
    {
        0, 0, 0, 0, 0,
        0, 0, 1, 1, 0,
        0, 0, 0, 1, 0,
        0, 0, 0, 1, 0,
        0, 0, 0, 0, 0
    },
    {
        0, 0, 0, 0, 0,
        0, 0, 0, 0, 0,
        0, 0, 0, 1, 0,
        0, 1, 1, 1, 0,
        0, 0, 0, 0, 0
    }
};

char shapeJ[SHAPE_STATES][SHAPE_SIZE] =
{
    {
        0, 0, 0, 0, 0,
        0, 0, 0, 1, 0,
        0, 0, 0, 1, 0,
        0, 0, 1, 1, 0,
        0, 0, 0, 0, 0
    },
    {
        0, 0, 0, 0, 0,
        0, 0, 0, 0, 0,
        0, 1, 0, 0, 0,
        0, 1, 1, 1, 0,
        0, 0, 0, 0, 0
    },
    {
        0, 0, 0, 0, 0,
        0, 1, 1, 0, 0,
        0, 1, 0, 0, 0,
        0, 1, 0, 0, 0,
        0, 0, 0, 0, 0
    },
    {
        0, 0, 0, 0, 0,
        0, 1, 1, 1, 0,
        0, 0, 0, 1, 0,
        0, 0, 0, 0, 0,
        0, 0, 0, 0, 0
    }
};

char shapeT[SHAPE_STATES][SHAPE_SIZE] =
{
    {
        0, 0, 0, 0, 0,
        0, 0, 0, 0, 0,
        0, 1, 1, 1, 0,
        0, 0, 1, 0, 0,
        0, 0, 0, 0, 0
    },
    {
        0, 0, 0, 0, 0,
        0, 0, 1, 0, 0,
        0, 1, 1, 0, 0,
        0, 0, 1, 0, 0,
        0, 0, 0, 0, 0
    },
    {
        0, 0, 0, 0, 0,
        0, 0, 1, 0, 0,
        0, 1, 1, 1, 0,
        0, 0, 0, 0, 0,
        0, 0, 0, 0, 0
    },
    {
        0, 0, 0, 0, 0,
        0, 0, 1, 0, 0,
        0, 0, 1, 1, 0,
        0, 0, 1, 0, 0,
        0, 0, 0, 0, 0
    }
};

char shapeS[SHAPE_STATES][SHAPE_SIZE] =
{
    {
        0, 0, 0, 0, 0,
        0, 1, 1, 0, 0,
        1, 1, 0, 0, 0,
        0, 0, 0, 0, 0,
        0, 0, 0, 0, 0
    },
    {
        0, 0, 1, 0, 0,
        0, 0, 1, 1, 0,
        0, 0, 0, 1, 0,
        0, 0, 0, 0, 0,
        0, 0, 0, 0, 0
    },
    {
        0, 0, 0, 0, 0,
        0, 1, 1, 0, 0,
        1, 1, 0, 0, 0,
        0, 0, 0, 0, 0,
        0, 0, 0, 0, 0
    },
    {
        0, 0, 1, 0, 0,
        0, 0, 1, 1, 0,
        0, 0, 0, 1, 0,
        0, 0, 0, 0, 0,
        0, 0, 0, 0, 0
    }
};

char shapeZ[SHAPE_STATES][SHAPE_SIZE] =
{
    {
        0, 0, 0, 0, 0,
        0, 0, 1, 1, 0,
        0, 0, 0, 1, 1,
        0, 0, 0, 0, 0,
        0, 0, 0, 0, 0
    },
    {
        0, 0, 1, 0, 0,
        0, 1, 1, 0, 0,
        0, 1, 0, 0, 0,
        0, 0, 0, 0, 0,
        0, 0, 0, 0, 0
    },
    {
        0, 0, 0, 0, 0,
        0, 0, 1, 1, 0,
        0, 0, 0, 1, 1,
        0, 0, 0, 0, 0,
        0, 0, 0, 0, 0
    },
    {
        0, 0, 1, 0, 0,
        0, 1, 1, 0, 0,
        0, 1, 0, 0, 0,
        0, 0, 0, 0, 0,
        0, 0, 0, 0, 0
    }
};

char shapeO[SHAPE_STATES][SHAPE_SIZE] =
{
    {
        0, 0, 0, 0, 0,
        0, 1, 1, 0, 0,
        0, 1, 1, 0, 0,
        0, 0, 0, 0, 0,
        0, 0, 0, 0, 0
    },
    {
        0, 0, 0, 0, 0,
        0, 1, 1, 0, 0,
        0, 1, 1, 0, 0,
        0, 0, 0, 0, 0,
        0, 0, 0, 0, 0
    },
    {
        0, 0, 0, 0, 0,
        0, 1, 1, 0, 0,
        0, 1, 1, 0, 0,
        0, 0, 0, 0, 0,
        0, 0, 0, 0, 0
    },
    {
        0, 0, 0, 0, 0,
        0, 1, 1, 0, 0,
        0, 1, 1, 0, 0,
        0, 0, 0, 0, 0,
        0, 0, 0, 0, 0
    }
};

char shapeI[SHAPE_STATES][SHAPE_SIZE] =
{
    {
        0, 0, 0, 0, 0,
        0, 0, 0, 0, 0,
        1, 1, 1, 1, 0,
        0, 0, 0, 0, 0,
        0, 0, 0, 0, 0
    },
    {
        0, 0, 1, 0, 0,
        0, 0, 1, 0, 0,
        0, 0, 1, 0, 0,
        0, 0, 1, 0, 0,
        0, 0, 0, 0, 0
    },
    {
        0, 0, 0, 0, 0,
        0, 0, 0, 0, 0,
        1, 1, 1, 1, 0,
        0, 0, 0, 0, 0,
        0, 0, 0, 0, 0
    },
    {
        0, 0, 1, 0, 0,
        0, 0, 1, 0, 0,
        0, 0, 1, 0, 0,
        0, 0, 1, 0, 0,
        0, 0, 0, 0, 0
    }
};
*/

Window::Window(const string& title, unsigned short width, unsigned short height) :
  m_title(title), m_width(width), m_height(height)
{
  m_pWindow = nullptr;
  m_pRenderer = nullptr;
  m_pTexture = nullptr;

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
    cerr << "Failed to initialize SDL Image" << endl;
    return false;
  }

  m_pWindow = SDL_CreateWindow(m_title.c_str(),
    SDL_WINDOWPOS_CENTERED,
    SDL_WINDOWPOS_CENTERED,
    m_width,
    m_height,
    SDL_WINDOW_SHOWN);

  if (m_pWindow == nullptr)
  {
    cerr << "Window Creation error: " << SDL_GetError() << endl;
    return false;
  }

  m_pRenderer = SDL_CreateRenderer(m_pWindow,
    -1,
    SDL_RENDERER_ACCELERATED |
    SDL_RENDERER_PRESENTVSYNC);

  if (m_pRenderer == nullptr)
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

  m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, surface);

  if (!m_pTexture)
  {
    cerr << "Failed to create the texture from surface" << endl;
    return false;
  }

  surface = IMG_Load("../Tetris/Images/Background2.jpg");

  m_pBckTexture = SDL_CreateTextureFromSurface(m_pRenderer, surface);

  if (!m_pBckTexture)
  {
    cerr << "Failed to create the background texture from surface" << endl;
    return false;
  }

  SDL_FreeSurface(surface);

  //Game initialization.
  GameInit();

  return true;
}

void Window::Update(float deltaTime)
{
  UpdateGround(deltaTime);
}

void Window::Render()
{
  SDL_SetRenderDrawColor(m_pRenderer, 120, 40, 40, 255);
  SDL_RenderClear(m_pRenderer);

  RenderGround();

  SDL_RenderPresent(m_pRenderer);
}

void Window::Destroy()
{
  Cleanup(m_pWindow, m_pRenderer, m_pTexture, m_pBckTexture);
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

void Window::GameInit()
{
  m_timer = 0;
  m_locked = 0;
  m_actualState = 0;
  m_piecePosX = START_X;
  m_piecePosY = START_Y;
  m_newPiece = false;

  SpawnPiece();
}

void Window::UpdateGround(float deltaTime)
{

  m_timer += deltaTime;

  /* TODO:
   * Add the spawned piece to the ground. (Done)
   * Move the piece.(Done)
   * Check if the piece has ground active spots under any of its squares.(Done)
   * Save the previous state of the piece to undo the changes in case of
     finding active spots under any of the piece's squares.(Done)
   * Lock the piece when one cycle has passed after finding an active spot
     under the piece.(Done)
   * Check if any row is full, erase the squares if it does.(Done)
   * Move all the active spots ABOVE.
   * Repeat the previous 2 steps until no full rows appear.
  */

  //Check if the time span has passed and the move has stopped
  //to update the ground.
  if (m_timer > TIME_SPAN)
  {
    if (m_locked == 0)
    {
      m_timer = 0;
      MoveDown();
    }
    else if(m_locked == 2)
    {
      m_timer = 0;

      //Check for each line the active spots.
      for (short i = GROUND_HEIGHT - 1; i >= 0; --i)
      {
        Uint32 counter = 0; //counter to know if the line is full.
        //Check in each column of the line for an active spot.
        for (short j = 0; j < GROUND_WIDTH; ++j)
        {
          if (ground.active[i][j])
          {
            //If the spot is active, then increase the counter
            counter++;
          }
        }

        if (counter == GROUND_WIDTH)
        {
          for (short k = 0; k < GROUND_WIDTH; ++k)
          {
            ground.active[i][k] = 0;
          }
        }
      }
      SpawnPiece();
    }
    else
    {
      m_locked++;
    }
  }
}

void Window::RenderGround()
{
  SDL_Rect playGround;

  playGround.w = ground.width;
  playGround.h = ground.height;
  playGround.x = ground.posX;
  playGround.y = ground.posY;
  SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255);
  SDL_RenderFillRect(m_pRenderer, &playGround);


  int pieceSize = ground.width / 10;
  for (size_t i = 0; i < GROUND_HEIGHT; ++i)
  {
    for (size_t j = 0; j < GROUND_WIDTH; ++j)
    {
      if (ground.active[i][j])
      {
        SDL_Rect piece = { ground.posX + (pieceSize * j),
                           ground.posY + (pieceSize * i),
                           pieceSize, pieceSize };
        SDL_RenderCopy(m_pRenderer, m_pTexture, nullptr, &piece);
      }
      else
      {
        SDL_Rect piece = { ground.posX + (pieceSize * j),
                           ground.posY + (pieceSize * i),
                           pieceSize, pieceSize };
        SDL_RenderCopy(m_pRenderer, m_pBckTexture, nullptr, &piece);
      }
    }
  }
}

void Window::SpawnPiece()
{
  short piece = 0;
  srand(time(NULL));
  piece = rand() % 7;

  /*DELETE THIS!! just for test purposes*/
  //piece = 6;
  /*************************************/

  for (short i = 0; i < SHAPE_STATES; ++i)
  {
    for (short j = 0; j < SHAPE_SIZE; ++j)
    {
      m_activePiece[i][j] = shapes[piece][i][j];
    }
  }

  //This loop assigns the values in the active piece to the play ground.
  for (int i = 0; i < 5; ++i)
  {
    for (int j = 0; j < 5; ++j)
    {
      if (ground.active[i + START_Y][j + START_X])
      {
        ground.active[i + START_Y-1][j + START_X] =
          m_activePiece[m_actualState][(i * SHAPE_OFFSET) + j];
      }
      ground.active[i + START_Y][j + START_X] =
        m_activePiece[m_actualState][(i * SHAPE_OFFSET) + j];
    }
  }

  m_locked = 0;

  //__debugbreak();
}

void Window::MoveDown()
{
  short rowsMoved = 0;
  for (int i = SHAPE_OFFSET-1; i >= 0; --i)
  {
    for (int j = 0; j < SHAPE_OFFSET; ++j)
    {
      if (m_activePiece[m_actualState][i * SHAPE_OFFSET + j])
      {
        short indexI = m_piecePosY + i;
        short indexJ = m_piecePosX + j;
        if (ground.active[indexI][indexJ] &&
            (ground.active[indexI + 1][indexJ] ||
             indexI >= GROUND_HEIGHT - 1))
        {
          RollBack(rowsMoved);
          m_locked = 1;
          m_piecePosY = START_Y;
          return;
        }
      }
    }

    //Move the row.
    for (int k = 0; k < SHAPE_OFFSET; ++k)
    {
      if (m_activePiece[m_actualState][i * SHAPE_OFFSET + k])
      {
        short indexI = m_piecePosY + i;
        short indexK = m_piecePosX + k;
        ground.active[indexI + 1][indexK] = ground.active[indexI][indexK];
        ground.active[indexI][indexK] = 0;
      }
    }
    rowsMoved++;
  }
  m_piecePosY++;
}

void Window::RollBack(short rowsCount)
{
  if (rowsCount <= 1)
    return;
  for (short i = 0; i < rowsCount; ++i)
  {
    for (int j = 0; j < SHAPE_OFFSET; ++j)
    {
      short index = ((SHAPE_OFFSET - 1) - i) * SHAPE_OFFSET + j;
      if (m_activePiece[m_actualState][index])
      {
        short indexI = m_piecePosY + (SHAPE_OFFSET) - i;
        short indexJ = m_piecePosX + j;
        ground.active[indexI - 1][indexJ] = ground.active[indexI][indexJ];
        ground.active[indexI][indexJ] = 0;
      }
    }
  }
}

void Window::LockPiece()
{
  memset(m_activePiece, 0, sizeof(m_activePiece));
  //__debugbreak();
}
