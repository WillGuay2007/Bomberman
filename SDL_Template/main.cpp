#include <Windows.h>
#include <SDL.h>
#include <iostream>
#include "Game.h"

using namespace std;

int main(int argc, char* argv[])
{
	if (SDL_Init(SDL_INIT_EVERYTHING))
	{
		SDL_Log("Error : %s\n", SDL_GetError());
		return 1;
	}

	SDL_Window* win = SDL_CreateWindow(
		"Space Invaders",
		SDL_WINDOWPOS_CENTERED, 
		SDL_WINDOWPOS_CENTERED,
		600,
		600,
		SDL_WINDOW_UTILITY
	);

	SDL_Renderer* renderer = SDL_CreateRenderer(win, 0, SDL_RENDERER_PRESENTVSYNC);

	if (renderer == nullptr)
	{
		SDL_Log("Error : %s\n", SDL_GetError());
		return 1;
	}

	bool running = true;
	SDL_Event events;

	Game* game = new Game(renderer);
	game->Init();

	while (running)
	{
		while (SDL_PollEvent(&events))
		{
			switch (events.type)
			{
				case SDL_QUIT:
					running = false;
					break;
				case SDL_KEYDOWN:
				{
					game->HandleKeys(events.key.keysym.sym);
					break;
				}
			}
		}

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		game->Update();
		game->Draw();

		// Push back buffer to the front buffer
		SDL_RenderPresent(renderer);
	}

	if (game != nullptr)
	{
		delete game;
		game = nullptr;
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(win);
	SDL_Quit();

	SDL_Log("PROGRAM END\n");
	return 0;
}
