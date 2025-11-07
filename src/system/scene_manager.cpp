//---------------------------------------------------------------------
// 
//  
// 
//
#include "scene_manager.hpp"
#include "DxLib.h"

namespace osiv {

//---------------------------------------------------------------------
// 
//  
// 
//
SceneManager::SceneManager()
    : mScene(0)
    , mNextScene(0)
    , mPrevScene(0)
    , mChangeFlag(false)
    , mFadeOutFlag(false)
    , mFadeInFlag(false)
    , mAlpha(0)
    , mParam1(0)
    , mFadeSpeed(10)
{
}

//---------------------------------------------------------------------
// 
//  
// 
//
SceneManager& SceneManager::ins()
{
    static SceneManager instance;
    return instance;
}

//---------------------------------------------------------------------
// 
//  初期化処理
// 
//
int SceneManager::initialize()
{
    mScene = SCENE_GAME;
    mFadeSpeed = 10;
    return 0;
}

//---------------------------------------------------------------------
// 
//  更新処理
// 
//
int SceneManager::update()
{
    //----- フェードアウト中の更新処理
    if (mFadeOutFlag) {
        mAlpha += mFadeSpeed;
        if (mAlpha >= 255) {
            mAlpha = 255;
            mFadeOutFlag = false;
            mPrevScene = mScene;
        }
    }
    //----- フェードイン中の更新処理
    if (mFadeInFlag) {
        mAlpha -= mFadeSpeed;
        if (mAlpha <= 0) {
            mAlpha = 0;
            mFadeInFlag = false;
        }
    }
    return 0;
}

//---------------------------------------------------------------------
// 
//  シーン変更
// 
//
void SceneManager::change(int aScene)
{
    //----- 変更中なら変更不可
    if (isChangeNow()) {
        return;
    }

    //----- 変更
    mFadeSpeed = 10;
    mChangeFlag = true;
    mNextScene = aScene;
    startFadeOut();
}

//---------------------------------------------------------------------
// 
//  前のシーンに戻る
// 
//
void SceneManager::changePrevScene()
{
    change(mPrevScene);
}

//---------------------------------------------------------------------
// 
//  フェードアウト開始
// 
//
void SceneManager::startFadeOut()
{
    mFadeOutFlag = true;
}


//---------------------------------------------------------------------
// 
//  フェードイン開始
// 
//
void SceneManager::startFadeIn()
{
    mFadeInFlag = true;
}

//---------------------------------------------------------------------
// 
//  次のシーンへ
// 
//
void SceneManager::startNextScene()
{
    mScene = mNextScene;
    startFadeIn();
    mChangeFlag = false;
}

//---------------------------------------------------------------------
// 
//  シーン変更可能
// 
//
bool SceneManager::isChangeable() const
{
    if (mChangeFlag && !mFadeOutFlag) {
        return true;
    }
    return false;
}
//---------------------------------------------------------------------
bool SceneManager::isChangeNow() const
{
    if (mChangeFlag) return true;
    if (mFadeOutFlag) return true;
    if (mFadeInFlag) return true;
    return false;
}

//---------------------------------------------------------------------
// 
//  setter
// 
//
void SceneManager::setParam1(int aParam) { mParam1 = aParam; }
//---------------------------------------------------------------------
void SceneManager::setFadeSpeed(int aSpeed) { mFadeSpeed = aSpeed; }

//---------------------------------------------------------------------
// 
//  getter
// 
//
int SceneManager::scene() const { return mScene; }
//---------------------------------------------------------------------
int SceneManager::alpha() const { return mAlpha; }
//---------------------------------------------------------------------
int SceneManager::nextScene() const { return mNextScene; }
//---------------------------------------------------------------------
int SceneManager::param1() const { return mParam1; }
//---------------------------------------------------------------------



} // namespace pokehito