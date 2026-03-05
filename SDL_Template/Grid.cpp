#include "Grid.h"
#include <ctime>
#include<cstdlib>

Grid::Grid(SDL_Texture* tilesTexture, SDL_Renderer* renderer, int width, int height, int tileSize, int numberOfBreakableWalls) :
	m_renderer(renderer),
	m_tilesTexture(tilesTexture),
	m_width(width),
	m_height(height),
	m_tileSize(tileSize),
	m_tiles(width, std::vector<Tile*>(height)),
	m_numberOfBreakableWalls(numberOfBreakableWalls)
{
}

Grid::~Grid()
{
	for (int column = 0; column < m_width; column++) {
		for (int row = 0; row < m_height; row++) {
			delete m_tiles[column][row];
			m_tiles[column][row] = nullptr;
		}
	}
}

std::vector<float> Grid::getCenter()
{
	return std::vector<float>();
}

void Grid::Init()
{
	std::cout << "Initializing the " << m_width << "x" << m_height << "grid.\n";
	for (int column = 0; column < m_width; column++) {
		for (int row = 0; row < m_height; row++) {
			ETileType chosenType = ETileType::Grass;
			if (column == 0 || row == 0 || column == m_width - 1 || row == m_height - 1 || (column % 2 == 0 && row % 2 == 0)) {
				chosenType = ETileType::Wall;
			}
			m_tiles[column][row] = new Tile(m_renderer, column * m_tileSize, row * m_tileSize, m_tileSize, m_tileSize, m_tilesTexture, chosenType);
		}
	}
	srand(time(nullptr));

	int placed = 0;

	int avaliableSpace = m_width * m_height / 2 - 20; //Jai choisi de faire une heuristique parce que fleme de trouver le calcul exact

	if (m_numberOfBreakableWalls > avaliableSpace) {
		std::cout << "Selected number of breakable walls is too high. Please choose a lower number\n";
		std::cout << avaliableSpace;
		return;
	}

	while (placed < m_numberOfBreakableWalls) {
		int column = rand() % m_width;
		int row = rand() % m_height;

		if (column < 3 && row < 3) continue; //Pour laisser un espace pour le joueur quand il spawn

		Tile* tile = m_tiles[column][row];
		if (tile->isWalkable()) {
			placed++;
			tile->SetTileType(ETileType::BreakableWall);
		}
	}
}

void Grid::Draw()
{
	for (int column = 0; column < m_width; column++) {
		for (int row = 0; row < m_height; row++) {
			m_tiles[column][row]->Draw();
		}
	}
}

Tile* Grid::GetTile(int x, int y)
{
	if (m_tiles.empty()) return nullptr;
	return m_tiles[x][y];
}

GridPosition Grid::WorldToGrid(Vector2 position)
{
	return {
		(int)(position.x / m_tileSize),
		(int)(position.y / m_tileSize)
	};
}

bool Grid::CanMoveToRect(const SDL_Rect& entityRect)
{
	for (int column = 0; column < m_width; column++)
	{
		for (int row = 0; row < m_height; row++)
		{
			Tile* tile = m_tiles[column][row];

			if (tile->isWalkable()) continue;

			SDL_Rect tileRect =
			{
				column * m_tileSize,
				row * m_tileSize,
				m_tileSize,
				m_tileSize
			};

			if (SDL_HasIntersection(&entityRect, &tileRect)) return false;
		}
	}

	return true;
}
