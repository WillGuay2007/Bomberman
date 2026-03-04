#pragma once
#include "SDL_image.h"
#include <string>

class Sprite
{
public:
	
	Sprite(SDL_Renderer* renderer, float a_X, float a_Y, float a_W, float a_H);
	~Sprite();

	bool LoadTexture(const std::string& filename);

	void Draw();

private:

	SDL_Renderer* m_renderer;
	SDL_Rect m_Rect;
	SDL_Texture* m_Texture;
};

