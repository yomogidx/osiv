//---------------------------------------------------------------------
// 
//  
// 
//
#include "backlog.hpp"
#include "DxLib.h"
#include "system/Input.hpp"
#include "system/system.hpp"
#include "system/scene_manager.hpp"

namespace osiv {

//---------------------------------------------------------------------
// 
//  
// 
//

//---------------------------------------------------------------------
// 
//  
// 
//
Backlog::Backlog()
    : mButtonBack()
    , mScenarioId(0)
    , mScenarioIdMax(0)
    , mScrollbarMove(false)
{
}

//---------------------------------------------------------------------
// 
//  
// 
//
void Backlog::initialize()
{
    mButtonBack.setPos(1150, 600);
    mButtonBack.setSize(100, 80);
}

//---------------------------------------------------------------------
// 
//  
// 
//
void Backlog::update()
{
    //----- キー操作
    keyProcess();

    //----- クリック操作
    click();

    //----- スクロール操作
    scroll();
}


//---------------------------------------------------------------------
// 
//  キー操作
// 
//
void Backlog::keyProcess()
{
    if (Input::ins().key(KEY_INPUT_UP) || Input::ins().key(KEY_INPUT_W)) {

    }
    if (Input::ins().key(KEY_INPUT_RIGHT) || Input::ins().key(KEY_INPUT_D)) {

    }
    if (Input::ins().key(KEY_INPUT_DOWN) || Input::ins().key(KEY_INPUT_S)) {

    }
    if (Input::ins().key(KEY_INPUT_LEFT) || Input::ins().key(KEY_INPUT_A)) {

    }

    //----- アクションキー
    if (Input::ins().key(KEY_INPUT_E) == 1) {
    }
}

//---------------------------------------------------------------------
// 
//  クリック操作
// 
//
void Backlog::click()
{
    //----- 左クリック押下時
    if (Input::ins().leftClick() == 1) {
        // 戻るボタン押下処理
        if (mButtonBack.isCollisionMouse()) {
            SceneManager::ins().changePrevScene();
        }

        // スクロールバー移動処理

    }

    //----- 右クリック押下時
    if (Input::ins().rightClick() == 1) {

    }
}

//---------------------------------------------------------------------
// 
//  スクロール操作
// 
//
void Backlog::scroll()
{
    int wheel = Input::ins().mouseWheel();
    mScenarioId += wheel * -1;
    if (mScenarioId < 0) {
        mScenarioId = 0;
    }
    if (mScenarioId > mScenarioIdMax) {
        mScenarioId = mScenarioIdMax;
    }
}

//---------------------------------------------------------------------
// 
//  スクロール操作
// 
//
double Backlog::scrollbarRate() const
{
    if (mScenarioIdMax == 0) { return 0; }
    return (double)mScenarioId / mScenarioIdMax;
}

//---------------------------------------------------------------------
// 
//  setter
// 
//
void Backlog::setScenarioId(int aId) { mScenarioId = aId; }
//---------------------------------------------------------------------
void Backlog::setScenarioIdMax(int aId) { mScenarioIdMax = aId; }

//---------------------------------------------------------------------
// 
//  getter
// 
//
const Button& Backlog::buttonBack() const { return mButtonBack; }

int Backlog::id1() const { return mScenarioId - 2; }
int Backlog::id2() const { return mScenarioId - 1; }
int Backlog::id3() const { return mScenarioId; }

} // namespace 