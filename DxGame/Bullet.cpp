#include "Bullet.h"
#include "DxLib.h"

Bullet::Bullet(float m_startX, float m_startY)
{
    m_bulletX = m_startX;
    m_bulletY = m_startY;

    m_isActive = true;
}

void Bullet::Update()
{
    m_bulletY -= 10.0f;

	if (m_bulletY < 0) m_isActive = false;
}

//’e‚Ì•`‰æ
void Bullet::Draw() const
{
    DrawCircle(
        (int)m_bulletX,
        (int)m_bulletY,
        5,
        GetColor(255, 255, 0),
        TRUE);
}

void Bullet::Destroy()
{
    m_isActive = false;
}

bool Bullet::IsActive() const
{
    return m_isActive;
}

float Bullet::GetX() const
{
    return m_bulletX;
}

float Bullet::GetY() const
{
    return m_bulletY;
}