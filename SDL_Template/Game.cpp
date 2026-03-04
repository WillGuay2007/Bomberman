#include "Game.h"
#include <iostream>

Game::Game(SDL_Renderer* renderer, int windowWidth, int windowHeight, int tileSize, int numberOfBreableWalls)
	:m_renderer(renderer)
	, m_Background(new Sprite(renderer, 0, 0, m_windowWidth, m_windowHeight))
	, m_tileSize(tileSize)
	, m_windowWidth(windowWidth)
	, m_windowHeight(windowHeight)
	, m_numberOfBreakableWalls(numberOfBreableWalls)
{
	m_tilesTexture = IMG_LoadTexture(renderer, "assets/Bomberman_assets.png");
	m_grid = new Grid(m_tilesTexture, renderer, m_windowWidth / m_tileSize, m_windowHeight / m_tileSize, m_tileSize, m_numberOfBreakableWalls);
}

Game::~Game()
{
	if (m_Background != nullptr)
	{
		delete m_Background;
		delete m_grid;
		m_grid = nullptr;
		m_Background = nullptr;
	}
}

void Game::Init()
{
	m_Background->LoadTexture("assets/background.jpg");
	m_grid->Init();
}

void Game::Update()
{

}

void Game::Draw()
{
	m_Background->Draw();
	m_grid->Draw();
}

void Game::HandleKeys(SDL_Keycode keyCode)
{
	switch (keyCode)
	{
	case SDLK_UP:
	case SDLK_w:
		std::cout << "Up";
		break;
	case SDLK_DOWN:
	case SDLK_s:
		std::cout << "Down";
		break;
	case SDLK_LEFT:
	case SDLK_d:
		std::cout << "Left";
		break;
	case SDLK_RIGHT:
	case SDLK_a:
		std::cout << "Right";
		break;
	}
}
