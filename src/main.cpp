//---------------------------------------------------------------------
#include "DxLib.h"
#include "system/system_manager.hpp"

//---------------------------------------------------------------------
// 
//  
// 
//
int WINAPI WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR lpCmdLine,
    int nCmdShow)
{
    //----- デバッグ用コンソール
    AllocConsole();
    FILE* fp;
    freopen_s(&fp, "CONOUT$", "w", stdout);
    freopen_s(&fp, "CONIN$", "r", stdin);

    //----- ゲーム処理
    osiv::SystemManager systemManager;
    systemManager.run();

    //----- 終了処理
    DxLib::DxLib_End();
    return false;
}