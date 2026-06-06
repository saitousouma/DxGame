#pragma once

class Player
{
public:
	float m_playerX;
	float m_playerY;

	int m_hp;

	Player();
	void Update();
	void Draw();
};