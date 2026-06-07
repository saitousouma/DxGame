#include "Input.h"
#include "DxLib.h"

Input::Input()
{
    for (int i = 0; i < 256; i++)
    {
        m_nowKey[i] = 0;
        m_oldKey[i] = 0;
    }
}

void Input::Update()
{
    for (int i = 0; i < 256; i++)
    {
        m_oldKey[i] = m_nowKey[i];
    }

    GetHitKeyStateAll(m_nowKey);
}

bool Input::IsPress(int keyCode) const
{
    return m_nowKey[keyCode] != 0;
}

bool Input::IsTrigger(int keyCode) const
{
    return m_nowKey[keyCode] && !m_oldKey[keyCode];
}