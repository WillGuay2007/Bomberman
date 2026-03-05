#include "Player.h"

Player::Player(SDL_Renderer* renderer, float x, float y, float w, float h, float speed, SDL_Texture* assetsTexture) : Sprite(renderer, x, y, w, h)
, m_playerSpeed(speed)
{
	texture = assetsTexture;
	LoadTextureFromAssets(4, 0);
}

Player::~Player()
{
}

void Player::Move(EDirection direction)
{
	switch (direction) {
	case EDirection::Up:
		Translate(0, -1 * m_playerSpeed);
		break;
	case EDirection::Down:
		Translate(0, 1 * m_playerSpeed);
		break;
	case EDirection::Right:
		Translate(1 * m_playerSpeed, 0);
		break;
	case EDirection::Left:
		Translate(-1 * m_playerSpeed, 0);
		break;
	default:
		return;
	}
}
