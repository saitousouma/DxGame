#pragma once

class Enemy
{
private:
    float m_enemyX;

    float m_enemyY;

    bool m_isActive;
public:
    Enemy(float m_startX);

    void Update();

    void Draw() const;

    void Destroy();

    bool IsActive() const;

    // 座標取得
    float GetX() const;
    float GetY() const;

    // サイズ取得
    int GetWidth() const;
    int GetHeight() const;
};