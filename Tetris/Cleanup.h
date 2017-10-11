#pragma once

#ifndef CLEANUP_H
#define CLEANUP_H

#include <utility>
#include "SDL.h"
#include "SDL_image.h"

using std::forward;

template<typename T, typename... Args>
void Cleanup(T* t, Args&&... args)
{
	Cleanup(t);

	Cleanup(forward<Args>(args)...);
}

template<>
inline void Cleanup<SDL_Window>(SDL_Window* window)
{
	if (!window)
	{
		return;
	}
	
	SDL_DestroyWindow(window);
}

template<>
inline void Cleanup<SDL_Renderer>(SDL_Renderer* renderer)
{
	if (!renderer)
	{
		return;
	}

	SDL_DestroyRenderer(renderer);
}

template<>
inline void Cleanup<SDL_Texture>(SDL_Texture* texture)
{
	if (!texture)
	{
		return;
	}

	SDL_DestroyTexture(texture);
}

template<>
inline void Cleanup<SDL_Surface>(SDL_Surface* surface)
{
	if (!surface)
	{
		return;
	}

	SDL_FreeSurface(surface);
}

#endif