#pragma once

class Enemy
{
public:
	float m_enemyX;
	float m_enemyY;

	bool m_active;

	Enemy(float m_ex);
	void Update();
	void Draw();
};
