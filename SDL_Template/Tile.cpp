#include "Tile.h"

Tile::Tile(SDL_Renderer* renderer, float posX, float posY, float width, float height, SDL_Texture* _texture, ETileType tileType) :
	Sprite(renderer, posX, posY, width, height)
	, m_tileType(tileType)
{

	texture = _texture;
	LoadTypeTexture();
}

bool Tile::isWalkable() const
{
	return m_tileType == ETileType::Grass;
}

bool Tile::isBreakable() const
{
	return m_tileType == ETileType::BreakableWall;
}

void Tile::SetTileType(ETileType newType)
{
	if (m_tileType == newType) return;
	m_tileType = newType;
	LoadTypeTexture();
}

void Tile::LoadTypeTexture()
{
	switch (m_tileType) {
	case ETileType::BreakableWall:
		LoadTextureFromAssets(4, 3);
		break;
	case ETileType::Wall:
		LoadTextureFromAssets(3, 3);
		break;
	case ETileType::Grass:
		LoadTextureFromAssets(0, 4);
		break;
	}
}
