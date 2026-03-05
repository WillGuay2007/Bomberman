#pragma once

#include <vector>
#include <iostream>
#include "Sprite.h"
#include "Powerup.h"
#include "EDirection.h"

class Player : public Sprite
{
public:
	Player(SDL_Renderer* renderer, float x, float y, float w, float h, float speed, SDL_Texture* assetsTexture);
	~Player();
	void Move(EDirection direction);
private:
	std::vector<Powerup*> m_activePowerups;
	float m_playerSpeed;
};

