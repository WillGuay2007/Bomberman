#include "Sprite.h"
#include <iostream>

Sprite::Sprite(SDL_Renderer* renderer, float x, float y, float w, float h)
	: texture(nullptr)
	, m_rect(SDL_Rect())
	, m_renderer(renderer)
{
	SetPosition(x, y);
	SetSize(w, h);
	m_srcRect = { 0,0,0,0 };
}

bool Sprite::LoadTexture(const std::string& filename)
{
	texture = IMG_LoadTexture(m_renderer, filename.c_str());
	if (texture == nullptr)
	{
		SDL_Log("Error loading texture %s", filename.c_str());
		return false;
	}

	return true;
}

void Sprite::LoadTextureFromAssets(int x, int y)
{
	m_srcRect.x = x * 16;
	m_srcRect.y = y * 16;
	m_srcRect.w = 16;
	m_srcRect.h = 16;
}

void Sprite::Draw()
{
	if (texture == nullptr) {
		std::cout << "Could not use Draw method on sprite. Must load texture first\n";
		return;
	}
	SDL_RenderCopyEx(m_renderer, texture, &m_srcRect, &m_rect, 0.0, nullptr, SDL_FLIP_NONE);
}

void Sprite::Translate(int x, int y)
{
	m_rect.x += x; m_rect.y += y;
}

void Sprite::SetPosition(float x, float y)
{
	m_rect.x = x; m_rect.y = y;
}

void Sprite::SetSize(float w, float h)
{
	m_rect.w = w; m_rect.h = h;
}

Vector2 Sprite::GetPosition()
{
	return Vector2(m_rect.x, m_rect.y);
}

Size Sprite::GetSize()
{
	return Size(m_rect.w, m_rect.h);
}

SDL_Rect& Sprite::GetRect()
{
	return m_rect;
}
