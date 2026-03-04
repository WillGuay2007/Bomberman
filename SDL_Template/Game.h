#pragma once
#include "SDL.h"
#include "Sprite.h"

class Game
{

public:
	Game(SDL_Renderer* renderer);
	~Game();

	void Init();

	void Update();
	void Draw();
	void HandleKeys(SDL_Keycode keyCode);

private:

	Sprite* m_Background;
	SDL_Renderer* m_renderer;
};

