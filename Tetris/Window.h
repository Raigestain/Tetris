#pragma once
#ifndef WINDOW_H
#define WINDOW_H

#include <string>
#include <iostream>
#include "Cleanup.h"

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
	void Update();
	void Render();

private:
	bool Init();
	void Destroy();
	void ProcessKeys(const SDL_KeyboardEvent &kbEvent);
	void UpdateGround();
	void RenderGround();

private:
	string m_title;
	unsigned short m_height;
	unsigned short m_width;
	bool m_isClosed;

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
	bool active[20][10];
};

#endif