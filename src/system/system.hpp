//---------------------------------------------------------------------
// 
//  system.hpp
// 
//
#pragma once
#include <string>

namespace osiv {

//---------------------------------------------------------------------
// 
//  
// 
//
class System {
public:
    ///
    static System& ins();
    void load();
    std::string createGameTitle() const;

    /// getter
    int windowSizeX() const;
    int windowSizeY() const;
    int windowDepthColor() const;
    std::string gameTitle() const;
    std::string gameVersion() const;

private:
    /// 
    static const int DefaultWindowSizeX;
    static const int DefaultWindowSizeY;
    static const int DefaultWindowDepthColor;
    static const std::string DefaultGameTitle;
    static const std::string DefaultGameVersion;

    ///
    System();

    /// member
    int mWindowSizeX;           //ウインドウサイズX軸方向(縦)
    int mWindowSizeY;           //ウインドウサイズY軸方向(横)
    int mWindowDepthColor;      //ウインドウ深度カラー
    std::string mGameTitle;     //ゲームタイトル
    std::string mGameVersion;   //ゲームバージョン
};

} // namespace qwitch