#include "DxLib.h"
#include "Game.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE,LPSTR, int)
{
    ChangeWindowMode(TRUE);

    SetGraphMode(1200,800,32);

	// DXライブラリの初期化
    if (DxLib_Init() == -1)
    {
        return -1;
    }

	//ダブルバッファリング
    SetDrawScreen(DX_SCREEN_BACK);

    Game game;

    //無限ループ
    while (ProcessMessage() == 0)
    {
        //描画を消す
        ClearDrawScreen();

        game.Update();
        game.Draw();

        //裏返す
        ScreenFlip();
    }

    DxLib_End();

    return 0;
}