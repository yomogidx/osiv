//---------------------------------------------------------------------
// 
//  
// 
//
#include "system.hpp"
#include "DxLib.h"

namespace osiv {

//---------------------------------------------------------------------
// 
//  
// 
//
//const int System::DefaultWindowSizeX = 1280;
//const int System::DefaultWindowSizeY = 720;
const int System::DefaultWindowSizeX = 960;
const int System::DefaultWindowSizeY = 540;
const int System::DefaultWindowDepthColor = 32;
const std::string System::DefaultGameTitle = "ゲームタイトルを設定してください";
const std::string System::DefaultGameVersion = "0.0.0";

//---------------------------------------------------------------------
// 
//  
// 
//
System::System()
    : mWindowSizeX(DefaultWindowSizeX)
    , mWindowSizeY(DefaultWindowSizeY)
    , mWindowDepthColor(DefaultWindowDepthColor)
    , mGameTitle(DefaultGameTitle)
    , mGameVersion(DefaultGameVersion)
{
}

//---------------------------------------------------------------------
// 
//  
// 
//
System& System::ins()
{
    static System instance;
    return instance;
}

//---------------------------------------------------------------------
// 
//  
// 
//
void System::load()
{
    /// システム設定の読込み
    //mWindowSizeX = 960;
    //mWindowSizeY = 540;
    mWindowSizeX = 1280;
    mWindowSizeY = 720;
    mWindowDepthColor = 32;
    mGameTitle = "ゲームタイトルを設定してください";
    mGameVersion = "1.0.0";
}

//---------------------------------------------------------------------
std::string System::createGameTitle() const
{
    std::string title;
    title = mGameTitle + " [Ver." + mGameVersion + "]";
    return title;
}

//---------------------------------------------------------------------
// 
//  
// 
//
int System::windowSizeX() const
{
    return mWindowSizeX;
}
//---------------------------------------------------------------------
int System::windowSizeY() const
{
    return mWindowSizeY;
}
//---------------------------------------------------------------------
int System::windowDepthColor() const
{
    return mWindowDepthColor;
}
//---------------------------------------------------------------------
std::string System::gameTitle() const
{
    return mGameTitle;
}
//---------------------------------------------------------------------
std::string System::gameVersion() const
{
    return mGameVersion;
}

}