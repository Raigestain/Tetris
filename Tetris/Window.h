#pragma once
#ifndef WINDOW_H
#define WINDOW_H

#include <string>
#include <iostream>
#include "Cleanup.h"

const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 920;
const Uint32 GROUND_WIDTH = 10;
const Uint32 GROUND_HEIGHT = 20;
const float TIME_SPAN = 750;
const short SHAPE_SIZE = 25;
const short SHAPE_STATES = 4;
const short SHAPE_NUM = 7;

using std::cout;
using std::cerr;
using std::cin;
using std::endl;
using std::ostream;
using std::string;

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
	bool Init();
	void Destroy();
	void ProcessKeys(const SDL_KeyboardEvent &kbEvent);
	void UpdateGround(float deltaTime);
	void RenderGround();
	void SpawnPiece();
	void LockPiece();

private:
	string m_title;
	unsigned short m_height;
	unsigned short m_width;
	short m_actualState;
	char m_activePiece[SHAPE_STATES][SHAPE_SIZE];
	bool m_isClosed;
	float m_timer;

	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
	SDL_Texture* m_texture;
};

struct GROUND
{
	int posX;
	int posY;
	int width;
	int height;
	char active[GROUND_HEIGHT][GROUND_WIDTH];
};

#endif
