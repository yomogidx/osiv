//---------------------------------------------------------------------
// 
//  
// 
//
#pragma once
#include "DxLib.h"
#include "system/fps_manager.hpp"
#include "game/game_render.hpp"
#include "title/title.hpp"
#include "title/title_render.hpp"
#include "backlog/backlog.hpp"
#include "backlog/backlog_render.hpp"
#include "saveload/saveload.hpp"
#include "saveload/saveload_render.hpp"

namespace osiv {

//---------------------------------------------------------------------
// 
//  
// 
//
class SystemManager {
public:
    /// コンストラクタ
    SystemManager();

    /// ゲーム開始
    int run();            // ゲームを実行します。

private:
    //----- 初期化処理
    int initialize();     // ゲーム情報を初期化します。

    //----- 更新処理
    int update();         // ゲーム情報を更新します。
    int updateScene();    // シーン毎の更新処理
    
    //----- 描画処理
    int render();         // ゲーム情報を更新します。
    int renderScene();    // シーン毎の描画処理

    //----- システム管理
    FpsManager mFpsManager;
    
    //----- ゲーム画面
    Game mGame;
    GameRender mGameRender;

    //----- タイトル画面
    Title mTitle;
    TitleRender mTitleRender;

    //----- バックログ画面
    Backlog mBacklog;
    BacklogRender mBacklogRender;

    //----- セーブロード画面
    Saveload mSaveload;
    SaveloadRender mSaveloadRender;

};

}