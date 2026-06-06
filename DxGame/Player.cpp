#include "DxLib.h"
#include "Player.h"

Player::Player()
{
	m_playerX = 320;
	m_playerY = 400;

	m_hp = 5;
}

void Player::Update()
{
	float m_speed = 5.0f;
	int m_ScreenWidth = 1200;
	int m_ScreenHeight = 800;

	//入力
	if (CheckHitKey(KEY_INPUT_W))
	{
		m_playerY -= m_speed;
	}

	if (CheckHitKey(KEY_INPUT_S))
	{
		m_playerY += m_speed;
	}

	if (CheckHitKey(KEY_INPUT_A))
	{
		m_playerX -= m_speed;
	}

	if (CheckHitKey(KEY_INPUT_D))
	{
		m_playerX += m_speed;
	}

	//画面外処理
	if (m_playerX < 0)
	{
		m_playerX = 0;
	}
	else if (m_playerX > m_ScreenWidth)
	{
		m_playerX = m_ScreenWidth;
	}

	if (m_playerY < 0)
	{
		m_playerY = 0;
	}
	else if (m_playerY > m_ScreenHeight)
	{
		m_playerY = m_ScreenHeight;
	}
}

//プレイヤー描画
void Player::Draw()
{
	DrawBox(
		(int)m_playerX, (int)m_playerY,
		(int)m_playerX + 30, (int)m_playerY + 30,
		GetColor(0, 255, 0),
		TRUE
	);
}