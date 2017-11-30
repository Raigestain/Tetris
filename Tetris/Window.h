#pragma once
#ifndef WINDOW_H
#define WINDOW_H

#include <string>
#include <iostream>
#include "Cleanup.h"

const int SCREEN_WIDTH = 1024;   //!< Width of the window screen
const int SCREEN_HEIGHT = 920;   //!< Height of the window screen.
const Uint32 GROUND_WIDTH = 10;  //!< Width of the play ground.
const Uint32 GROUND_HEIGHT = 20; //!< Height of the play ground.
const float TIME_SPAN = 600;     //!< Number of ms for ground update.
const short SHAPE_OFFSET = 5;    //!< The row offset for 
const short SHAPE_SIZE = 25;     //!< Size of the array containing the piece.
const short SHAPE_STATES = 4;    //!< Number of the shapes' states.
const short SHAPE_NUM = 7;       //!< Number of different pieces.
const short START_X = 3;         //!< Starting x position of the piece.
const short START_Y = 0;         //!< Starting y position of the piece.


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
  void MoveDown();
  void RollBack(short rowsCount);
  void LockPiece();

private:
  //Window variables.
  string m_title;
  unsigned short m_height;
  unsigned short m_width;
  SDL_Window* m_pWindow;
  SDL_Renderer* m_pRenderer;
  SDL_Texture* m_pTexture;
  SDL_Texture* m_pBckTexture;
  bool m_isClosed;

  //Game variables.
  float m_timer;
  short m_actualState;
  short m_piecePosX;
  short m_piecePosY;
  unsigned char m_activePiece[SHAPE_STATES][SHAPE_SIZE];
  unsigned char m_locked;
  bool m_newPiece; //Use this to let the piece be in the top part of the ground.

};

#endif
