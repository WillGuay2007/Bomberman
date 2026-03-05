#pragma once
#include "SDL.h"
#include "Sprite.h"
#include "Grid.h"
#include "Player.h"

class Game
{

public:
	Game(SDL_Renderer* renderer, int windowWidth, int windowHeight, int tileSize, int numberOfBreableWalls);
	~Game();

	void Init();

	void Update();
	void Draw();

private:
	Player* m_player;

	int m_windowWidth;
	int m_windowHeight;
	int m_tileSize;
	int m_numberOfBreakableWalls;

	Grid* m_grid;
	Sprite* m_Background;
	SDL_Texture* m_assetsTexture;
	SDL_Renderer* m_renderer;
};

