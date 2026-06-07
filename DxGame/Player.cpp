#include "Player.h"
#include "DxLib.h"

Player::Player()
{
    m_playerX = 600.0f;
    m_playerY = 700.0f;

    m_playerHP = 5;
}

void Player::Update(const Input& input)
{
    const float speed = 6.0f;

    //移動処理
	if (input.IsPress(KEY_INPUT_W)) m_playerY -= speed;
	if (input.IsPress(KEY_INPUT_S)) m_playerY += speed;
	if (input.IsPress(KEY_INPUT_A)) m_playerX -= speed;
	if (input.IsPress(KEY_INPUT_D)) m_playerX += speed;

    // 左端
	if (m_playerX < 0) m_playerX = 0;
    // 右端
	if (m_playerX > 1170) m_playerX = 1170;
    // 上端
	if (m_playerY < 0) m_playerY = 0;
    // 下端
	if (m_playerY > 770) m_playerY = 770;
}

void Player::Draw() const
{
    DrawBox(
        (int)m_playerX,
        (int)m_playerY,
        (int)m_playerX + 30,
        (int)m_playerY + 30,
        GetColor(0, 255, 0),
        TRUE);
}

void Player::Damage(int value)
{
    m_playerHP -= value;

	if (m_playerHP < 0) m_playerHP = 0;
}

bool Player::IsDead() const
{
    return m_playerHP <= 0;
}

int Player::GetHP() const
{
    return m_playerHP;
}

float Player::GetX() const
{
    return m_playerX;
}

float Player::GetY() const
{
    return m_playerY;
}

int Player::GetWidth() const
{
    return 30;
}

int Player::GetHeight() const
{
    return 30;
}