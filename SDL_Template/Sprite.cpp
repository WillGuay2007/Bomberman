#include "Sprite.h"
#include <iostream>

Sprite::Sprite(SDL_Renderer* renderer, float x, float y, float w, float h)
	: m_Texture(nullptr)
	, m_Rect(SDL_Rect())
	, m_renderer(renderer)
{
	m_Rect.x = x;
	m_Rect.y = y;
	m_Rect.w = w;
	m_Rect.h = h;
}

Sprite::~Sprite()
{
	if (m_Texture != nullptr)
	{
		SDL_DestroyTexture(m_Texture);
		m_Texture = nullptr;
	}
}

bool Sprite::LoadTexture(const std::string& filename)
{
	m_Texture = IMG_LoadTexture(m_renderer, filename.c_str());
	if (m_Texture == nullptr)
	{
		SDL_Log("Error loading texture %s", filename.c_str());
		return false;
	}

	return true;
}

void Sprite::Draw()
{
	if (m_Texture == nullptr) {
		std::cout << "Could not use Draw method on sprite. Must load texture first" << std::endl;
	}
	SDL_RenderCopyEx(m_renderer, m_Texture, nullptr, &m_Rect, 0.0, nullptr, SDL_FLIP_NONE);
}
