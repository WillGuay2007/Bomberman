#include "Game.h"
#include <iostream>

Game::Game(SDL_Renderer* renderer)
	:m_renderer(renderer)
	,m_Background(new Sprite(renderer, 0, 0, 1000, 1000))
{

}

Game::~Game()
{
	if (m_Background != nullptr)
	{
		delete m_Background;
		m_Background = nullptr;
	}
}

void Game::Init()
{
	m_Background->LoadTexture("assets/background.jpg");
}

void Game::Update()
{

}

void Game::Draw()
{
	m_Background->Draw();
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
