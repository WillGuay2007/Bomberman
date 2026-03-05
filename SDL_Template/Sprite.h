#pragma once
#include <string>
#include "SDL_image.h"
#include "TransformStructs.h"

class Sprite
{
public:
	
	Sprite(SDL_Renderer* renderer, float a_X, float a_Y, float a_W, float a_H);

	bool LoadTexture(const std::string& filename);
	void LoadTextureFromAssets(int x, int y);

	void Draw();
	void Translate(int x, int y);
	void SetPosition(float x, float y);
	void SetSize(float w, float h);
	Vector2 GetPosition();
	Size GetSize();
	SDL_Rect& GetRect();

protected:
	SDL_Texture* texture;
private:

	SDL_Renderer* m_renderer;
	SDL_Rect m_rect;
	SDL_Rect m_srcRect;
};

