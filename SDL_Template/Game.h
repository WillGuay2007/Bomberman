#pragma once
#include "SDL.h"
#include "Sprite.h"
#include "Grid.h"

class Game
{

public:
	Game(SDL_Renderer* renderer, int windowWidth, int windowHeight, int tileSize, int numberOfBreableWalls);
	~Game();

	void Init();

	void Update();
	void Draw();
	void HandleKeys(SDL_Keycode keyCode);

private:
	int m_windowWidth;
	int m_windowHeight;
	int m_tileSize;
	int m_numberOfBreakableWalls;
	Grid* m_grid;
	Sprite* m_Background;
	SDL_Texture* m_tilesTexture;
	SDL_Renderer* m_renderer;
};

