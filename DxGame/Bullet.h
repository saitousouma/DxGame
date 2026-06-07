#pragma once

class Bullet
{
private:
    float m_bulletX;

    float m_bulletY;

    bool m_isActive;
public:
    Bullet(float startX, float startY);

    void Update();

    void Draw() const;

    void Destroy();

    bool IsActive() const;

    // À•Wæ“¾
    float GetX() const;
    float GetY() const;
};