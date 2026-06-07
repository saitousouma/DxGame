#include "DxLib.h"
#include "Game.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE,LPSTR, int)
{
    ChangeWindowMode(TRUE);

    SetGraphMode(1200,800,32);

    if (DxLib_Init() == -1)
    {
        return -1;
    }

    SetDrawScreen(DX_SCREEN_BACK);

    Game game;

    while (ProcessMessage() == 0)
    {
        ClearDrawScreen();

        game.Update();
        game.Draw();

        ScreenFlip();
    }

    DxLib_End();

    return 0;
}