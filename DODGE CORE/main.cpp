#include "DxLib.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    // ウィンドウモード
    ChangeWindowMode(TRUE);

    // 初期化（失敗したら終了）
    if (DxLib_Init() == -1) return -1;

    // 裏画面描画（ちらつき防止）
    SetDrawScreen(DX_SCREEN_BACK);

    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
    {
        ClearDrawScreen();

        DrawString(20, 20, "DXLib: Hello", GetColor(255, 255, 255));

        ScreenFlip();
    }

    DxLib_End();
    return 0;
}
