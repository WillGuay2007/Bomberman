#pragma once

#include "Sprite.h"

enum ETileType
{
	Grass,
	BreakableWall,
	Wall
};

class Tile : public Sprite
{
public:
	Tile(SDL_Renderer* renderer, float posX, float posY, float width, float height, SDL_Texture* texture, ETileType tileType);

	bool isWalkable() const;
	bool isBreakable() const;
	void SetTileType(ETileType newType);
	void LoadTypeTexture();
private:
	ETileType m_tileType;
};

