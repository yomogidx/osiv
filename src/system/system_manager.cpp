//---------------------------------------------------------------------
// 
//  
// 
//
#include "system_manager.hpp"
#include "DxLib.h"
#include "system/input.hpp"
#include "system/System.hpp"
#include "assets/assets_manager.hpp"
//#include "assets/images.hpp"
#include "system/scene_manager.hpp"

namespace osiv {

//---------------------------------------------------------------------
// 
//  
// 
//
SystemManager::SystemManager()
    : mFpsManager()
    , mGame()
    , mGameRender()
    , mTitle()
    , mTitleRender()
    , mBacklog()
    , mBacklogRender()
{

}

//---------------------------------------------------------------------
// 
//  
// 
//
int SystemManager::run()
{
    //----- 初期処理
    if (initialize() != 0) {
        return -1;
    }

    //----- 更新処理
    while (1) {
        if (DxLib::ProcessMessage() != 0) { return -1; }
        if (DxLib::ClearDrawScreen() != 0) { return -1; }
        if (update() != 0) { return -1; }
    }

    //----- 終了処理
    return 0;
}

//---------------------------------------------------------------------
// 
//  
// 
//
int SystemManager::initialize()
{
    //----- システム初期化
    System::ins().load();
    if (DxLib::SetGraphMode(
        System::ins().windowSizeX(),
        System::ins().windowSizeY(),
        System::ins().windowDepthColor()) ||
        DxLib::SetWindowSizeChangeEnableFlag(TRUE) ||
        //DxLib::SetWindowSizeExtendRate(0.3) ||
        DxLib::ChangeWindowMode(TRUE) ||
        DxLib::SetWindowText(
            System::ins().createGameTitle().c_str()) ||
        DxLib::SetOutApplicationLogValidFlag(FALSE) ||
        DxLib::DxLib_Init() ||
        DxLib::SetDrawScreen(DX_SCREEN_BACK) ||
        DxLib::SetAlwaysRunFlag(TRUE)) {
        return -1;
    }

    //----- アセット読み込み
    AssetsManager::ins().load();

    //----- シーン初期化
    SceneManager::ins().initialize();
    mTitle.initialize();
    mGame.initialize();
    mBacklog.initialize();
    mSaveload.initialize();

    return 0;
}

//---------------------------------------------------------------------
// 
//  
// 
//
int SystemManager::update()
{
    //----- FPS調整
    mFpsManager.wait();
    mFpsManager.update();

    //----- 入力値更新
    Input::ins().update();

    //----- 更新処理
    updateScene();

    //----- 描画処理
    render();
    //DxLib::DrawFormatString(0, 0, GetColor(255, 0, 0), "FPS【%lf】", mFpsManager.fps());
    DxLib::ScreenFlip();
    return 0;
}

//---------------------------------------------------------------------
// 
//  シーンごとの更新処理
// 
//
int SystemManager::updateScene()
{
    //----- シーンの更新処理
    SceneManager::ins().update();
    if (SceneManager::ins().isChangeable()) {
        // シーン変更時処理
        int nextScene = SceneManager::ins().nextScene();

        if (nextScene == SceneManager::SCENE_BACKLOG) {
            int id = mGame.scenarioId();
            mBacklog.setScenarioId(id);
            mBacklog.setScenarioIdMax(id);
        }
        if (nextScene == SceneManager::SCENE_SAVE) {
            int id = mGame.scenarioId();
            mSaveload.setScenarioId(id);
            mSaveload.setMode(Saveload::MODE_SAVE);
        }
        if (nextScene == SceneManager::SCENE_LOAD) {
            int id = mGame.scenarioId();
            mSaveload.setScenarioId(id);
            mSaveload.setMode(Saveload::MODE_LOAD);
        }
        if (nextScene == SceneManager::SCENE_GAME) {
            int id = SceneManager::ins().param1();
            mGame.jumpScenario(id);
        }

        // シーン変更
        SceneManager::ins().startNextScene();
    }

    //----- タイトル画面の更新処理
    if (SceneManager::ins().scene() == SceneManager::SCENE_TITLE) {
        mTitle.update();
    }
    //----- ゲーム画面の更新処理
    else if (SceneManager::ins().scene() == SceneManager::SCENE_GAME) {
        mGame.update();
    }
    //----- バックログ画面の更新処理
    else if (SceneManager::ins().scene() == SceneManager::SCENE_BACKLOG) {
        mBacklog.update();
    }
    //----- セーブ画面の更新処理
    else if (SceneManager::ins().scene() == SceneManager::SCENE_SAVE) {
        mSaveload.update();
    }
    //----- ロード画面の更新処理
    else if (SceneManager::ins().scene() == SceneManager::SCENE_LOAD) {
        mSaveload.update();
    }

    return 0;
}

//---------------------------------------------------------------------
// 
//  描画処理
// 
//
int SystemManager::render()
{
    //----- シーンの描画処理
    renderScene();

    //----- フェードイン/アウト
    int alpha = SceneManager::ins().alpha();
    SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
    DrawBox(0, 0,
        System::ins().windowSizeX(),
        System::ins().windowSizeY(),
        DxLib::GetColor(0, 0, 0), TRUE);
    SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

    return 0;
}

//---------------------------------------------------------------------
// 
//  シーンの描画処理
// 
//
int SystemManager::renderScene()
{
    //----- タイトル画面
    if (SceneManager::ins().scene() == SceneManager::SCENE_TITLE) {
        mTitleRender.render(mTitle);
    }
    //----- ゲーム画面
    else if (SceneManager::ins().scene() == SceneManager::SCENE_GAME) {
        mGameRender.render(mGame);
    }
    //----- バックログ画面
    else if (SceneManager::ins().scene() == SceneManager::SCENE_BACKLOG) {
        mBacklogRender.render(mBacklog);
    }
    //----- セーブ画面
    else if (SceneManager::ins().scene() == SceneManager::SCENE_SAVE) {
        mSaveloadRender.render(mSaveload);
    }
    //----- ロード画面
    else if (SceneManager::ins().scene() == SceneManager::SCENE_LOAD) {
        mSaveloadRender.render(mSaveload);
    }

    return 0;
}


} // namespace qwitch