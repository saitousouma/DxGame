#include "DxLib.h"
#include "Enemy.h"

Enemy::Enemy(float m_ex)
{
	m_enemyX = m_ex;
	m_enemyY = -20;
	m_active = true;
}

void Enemy::Update()
{
	int m_ScreenHeight = 800;

	//下に移動
	m_enemyY += 3.0f;

	//画面外に行ったら消す
	if (m_enemyY > m_ScreenHeight)
	{
		m_active = false;
	}
}

//エネミーの描画
void Enemy::Draw()
{
	DrawBox(
		(int)m_enemyX, (int)m_enemyY,
		(int)m_enemyX + 30, (int)m_enemyY + 30,
		GetColor(255, 0, 0),
		TRUE
	);
}