#pragma once
#ifndef WINDOW_H
#define WINDOW_H

#include <string>
#include <iostream>
#include "Cleanup.h"

const int SCREEN_WIDTH     = 1024; //!< Width of the window screen
const int SCREEN_HEIGHT    = 920;  //!< Height of the window screen.
const Uint32 GROUND_WIDTH  = 10;   //!< Width of the play ground.
const Uint32 GROUND_HEIGHT = 20;   //!< Height of the play ground.
const float TIME_SPAN      = 750;  //!< Number of ms for ground update.
const short SHAPE_SIZE     = 25;   //!< Size of the array containing the piece.
const short SHAPE_STATES   = 4;    //!< Number of the shapes' states.
const short SHAPE_NUM      = 7;    //!< Number of different pieces.

using std::cout;
using std::cerr;
using std::cin;
using std::endl;
using std::ostream;
using std::string;

struct GROUND
{
  int posX;
  int posY;
  int width;
  int height;
  char active[GROUND_HEIGHT][GROUND_WIDTH];
};

class Window
{
public:
	Window(const string& title, unsigned short width, unsigned short height);
	~Window();

  
	inline bool isClosed() const { return m_isClosed; }

	void PollEvents();
	void Update(float deltaTime);
	void Render();

private:
  //Window functions.
	bool Init();
	void Destroy();
	void ProcessKeys(const SDL_KeyboardEvent &kbEvent);

  //Game functions.
  void GameInit();
	void UpdateGround(float deltaTime);
	void RenderGround();
	void SpawnPiece();
	void LockPiece();

private:
  //Window variables.
	string m_title;
	unsigned short m_height;
	unsigned short m_width;
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	SDL_Texture* m_pTexture;
  bool m_isClosed;

  //Game variables.
  float m_timer;
	short m_actualState;
	char m_activePiece[SHAPE_STATES][SHAPE_SIZE];
  bool m_locked;
};

#endif
