#pragma once

#include "Sprite.h"

enum TileType
{
	Grass,
	BreakableWall,
	Wall
};

class Tile : public Sprite
{
public:
	Tile(SDL_Renderer* renderer, float posX, float posY, float width, float height, SDL_Texture* texture, TileType tileType);

	bool isWalkable() const;
	bool isBreakable() const;
	void SetTileType(TileType newType);
	void LoadTypeTexture();
private:
	TileType m_tileType;
};

