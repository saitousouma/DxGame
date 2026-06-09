#pragma once

class Bullet
{
private:
    float m_bulletX;

    float m_bulletY;

    bool m_isActive;
public:
    Bullet(float m_startX, float m_startY);

    void Update();

    void Draw() const;

    void Destroy();

    bool IsActive() const;

    // À•Wæ“¾
    float GetX() const;
    float GetY() const;
};