#include "Enemy.h"
#include "DxLib.h"

Enemy::Enemy(float startX)
{
    m_enemyX = startX;
    m_enemyY = -30.0f;

    m_isActive = true;
}

void Enemy::Update()
{
    m_enemyY += 3.0f;

    // 画面外へ出たら削除
    if (m_enemyY > 800)
    {
        m_isActive = false;
    }
}

//エネミーの描画
void Enemy::Draw() const
{
    DrawBox(
        (int)m_enemyX,
        (int)m_enemyY,
        (int)m_enemyX + 30,
        (int)m_enemyY + 30,
        GetColor(255, 0, 0),
        TRUE);
}

void Enemy::Destroy()
{
    m_isActive = false;
}

bool Enemy::IsActive() const
{
    return m_isActive;
}

float Enemy::GetX() const
{
    return m_enemyX;
}

float Enemy::GetY() const
{
    return m_enemyY;
}

int Enemy::GetWidth() const
{
    return 30;
}

int Enemy::GetHeight() const
{
    return 30;
}