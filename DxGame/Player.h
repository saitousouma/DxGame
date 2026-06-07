#pragma once

#include "Input.h"

class Player
{
private:
    float m_playerX;

    float m_playerY;

    int m_playerHP;
public:
    Player();

    void Update(const Input& input);

    void Draw() const;

    void Damage(int value);

    bool IsDead() const;

    int GetHP() const;

    // 座標取得
    float GetX() const;
    float GetY() const;

    // サイズ取得
    int GetWidth() const;
    int GetHeight() const;
};