#pragma once

#include <iostream>
#include <vector>
#include "Tile.h"
#include "TransformStructs.h"

class Grid
{
public:
	Grid(SDL_Texture* tilesTexture, SDL_Renderer* renderer, int width, int height, int tileSize, int numberOfBreakableWalls);
	~Grid();

	std::vector<float> getCenter();
	void Init();
	void Draw();
	bool CanMoveToRect(const SDL_Rect& playerRect);
	Tile* GetTile(int x, int y);
	GridPosition WorldToGrid(Vector2 position);

private:
	SDL_Renderer* m_renderer;
	SDL_Texture* m_tilesTexture;
	std::vector<std::vector<Tile*>> m_tiles;
	int m_width;
	int m_height;
	int m_tileSize;
	int m_numberOfBreakableWalls;
};

