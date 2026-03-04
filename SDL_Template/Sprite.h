#pragma once
#include "SDL_image.h"
#include <string>

class Sprite
{
public:
	
	Sprite(SDL_Renderer* renderer, float a_X, float a_Y, float a_W, float a_H);
	virtual ~Sprite();

	bool LoadTexture(const std::string& filename);
	void LoadTextureFromAssets(int x, int y);

	void Draw();

protected:
	SDL_Texture* texture;
private:

	SDL_Renderer* m_renderer;
	SDL_Rect m_rect;
	SDL_Rect m_srcRect;

};

