#include "Game.h"
#include <iostream>

const float PLAYER_SPEED = 1;

Game::Game(SDL_Renderer* renderer, int windowWidth, int windowHeight, int tileSize, int numberOfBreableWalls)
	:m_renderer(renderer)
	, m_Background(new Sprite(renderer, 0, 0, m_windowWidth, m_windowHeight))
	, m_tileSize(tileSize)
	, m_windowWidth(windowWidth)
	, m_windowHeight(windowHeight)
	, m_numberOfBreakableWalls(numberOfBreableWalls)
{
	m_assetsTexture = IMG_LoadTexture(renderer, "assets/Bomberman_assets.png");
	m_grid = new Grid(m_assetsTexture, renderer, m_windowWidth / m_tileSize, m_windowHeight / m_tileSize, m_tileSize, m_numberOfBreakableWalls);
	m_player = new Player(renderer, m_tileSize + m_tileSize / 2, m_tileSize + m_tileSize / 2, m_tileSize/1.5, m_tileSize/1.5, PLAYER_SPEED, m_assetsTexture);
    m_player->Translate(-m_player->GetSize().width / 2, -m_player->GetSize().height / 2);
}

Game::~Game()
{
    if (m_assetsTexture != nullptr)
    {
        SDL_DestroyTexture(m_assetsTexture);
        m_assetsTexture = nullptr;
    }
	delete m_Background;
	delete m_grid;
	delete m_player;
	m_player = nullptr;
	m_grid = nullptr;
	m_Background = nullptr;
}

void Game::Init()
{
	m_Background->LoadTexture("assets/background.jpg");
	m_grid->Init();
}

void Game::Update()
{
    const Uint8* keys = SDL_GetKeyboardState(NULL);

    int dx = 0;
    int dy = 0;

    if (keys[SDL_SCANCODE_W] || keys[SDL_SCANCODE_UP]) dy -= PLAYER_SPEED;
    if (keys[SDL_SCANCODE_S] || keys[SDL_SCANCODE_DOWN]) dy += PLAYER_SPEED;
    if (keys[SDL_SCANCODE_A] || keys[SDL_SCANCODE_LEFT]) dx -= PLAYER_SPEED;
    if (keys[SDL_SCANCODE_D] || keys[SDL_SCANCODE_RIGHT]) dx += PLAYER_SPEED;

    SDL_Rect nextRect = m_player->GetRect();

    nextRect.x += dx;

    if (m_grid->CanMoveToRect(nextRect))
    {
        m_player->SetPosition(nextRect.x, nextRect.y);
    }

    nextRect = m_player->GetRect();
    nextRect.y += dy;

    if (m_grid->CanMoveToRect(nextRect))
    {
        m_player->SetPosition(nextRect.x, nextRect.y);
    }
    
}

void Game::Draw()
{
	m_Background->Draw();
	m_grid->Draw();
    m_player->Draw();
}