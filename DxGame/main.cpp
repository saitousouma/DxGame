#include "DxLib.h"
#include "main.h"

int WINAPI WinMain(HINSTANCE hIns, HINSTANCE hPrevIns,
	LPSTR lpCmdLine, int nCmdShow)
{
	Main main;
	main.Init();
	main.Update();
	main.Exit();
	return 0;
}

Main::Main()
{

}

void Main::Init()
{
	SetGraphMode(m_ScreenWidth, m_ScreenHeight, 32);

	//ウィンドウモード
	ChangeWindowMode(TRUE);

	//初期化
	if (DxLib_Init() == -1)
	{
		return;
	}

	//ダブルバッファリング
	SetDrawScreen(DX_SCREEN_BACK);

	SetFontSize(40);
}

void Main::Update()
{
	//無限ループ
	while (true)
	{
		//画面を消す
		ClearDrawScreen();

		//裏画面を表画面にコピー
		ScreenFlip();

		if (ProcessMessage() < 0)
		{
			break;
		}
		if (CheckHitKey(KEY_INPUT_ESCAPE))
		{
			break;
		}
	}
}

void Main::Exit()
{
	DxLib_End();
}