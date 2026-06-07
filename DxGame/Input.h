#pragma once

class Input
{
private:
    // 現在のフレームのキー状態
    char m_nowKey[256];

    // 前フレームのキー状態
    char m_oldKey[256];
public:
    Input();

    void Update();

    // 押しっぱなし判定
    bool IsPress(int keyCode) const;

    // 押した瞬間判定
    bool IsTrigger(int keyCode) const;
};
