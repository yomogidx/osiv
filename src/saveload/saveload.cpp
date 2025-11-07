//---------------------------------------------------------------------
// 
//  
// 
//
#include "saveload.hpp"
#include "DxLib.h"
#include "system/system.hpp"
#include "assets/images.hpp"
#include "assets/data.hpp"
#include "system/input.hpp"
#include "system/scene_manager.hpp"

namespace osiv {

//---------------------------------------------------------------------
// 
//  
// 
//
Saveload::Saveload()
    : mMode()
    , mButtonData()
    , mButtonPage()
    , mButtonBack()
    , mPage(0)
    , mScenarioId(0)
{
}

//---------------------------------------------------------------------
// 
//  
// 
//
void Saveload::initialize()
{
    //----- セーブデータボタン
    for (int i = 0; i < 10; i++) {
        int x = i % 2;
        int y = i / 2;
        Button s;
        s.setPosX(50 + (514 + 26) * x);
        s.setPosY(100 + (114 + 6) * y);
        s.setSizeX(514);
        s.setSizeY(114);
        mButtonData.push_back(s);
    }

    //----- ページ番号ボタン
    for (int i = 0; i < 20; i++) {
        int x = i / 10;
        int y = i % 10;
        Button s;
        s.setPosX(1150 + (40 + 10) * x);
        s.setPosY(100 + (40 + 10) * y);
        s.setSizeX(40);
        s.setSizeY(40);
        mButtonPage.push_back(s);
    }

    //----- 戻るボタン
    mButtonBack.setPosX(1140);
    mButtonBack.setPosY(620);
    mButtonBack.setSizeX(100);
    mButtonBack.setSizeY(80);
}

//---------------------------------------------------------------------
// 
//  
// 
//
void Saveload::update()
{
    //----- キー操作
    keyProcess();

    //----- クリック操作
    click();
}

//---------------------------------------------------------------------
// 
//  
// 
//
void Saveload::keyProcess()
{

}

//---------------------------------------------------------------------
// 
//  
// 
//
void Saveload::click()
{
    //----- 左クリック押下時
    if (Input::ins().leftClick() == 1) {
        // 戻るボタン
        if (mButtonBack.isCollisionMouse()) {
            SceneManager::ins().changePrevScene();
            SceneManager::ins().setParam1(mScenarioId);
        }
        // セーブデータ
        for (int i = 0; i < 10; i++) {
            if (mButtonData[i].isCollisionMouse()) {
                int num = i + mPage * 10;
                int id = Data::ins().saveData(num).scenarioId();

                if (mMode == MODE_SAVE) {
                    Data::ins().save(num, mScenarioId);
                }
                if (mMode == MODE_LOAD) {
                    if (id >= 0) {
                        SceneManager::ins().change(SceneManager::SCENE_GAME);
                        SceneManager::ins().setParam1(id);
                    }
                }
                break;
            }
        }
        // ページ番号
        for (int i = 0; i < 20; i++) {
            if (mButtonPage[i].isCollisionMouse()) {
                mPage = i;
            }
        }
    }

    //----- 右クリック押下時
    if (Input::ins().rightClick() == 1) {
    }
}

//---------------------------------------------------------------------
// 
//  カウント
// 
//
int Saveload::countButtonData() const { return (int)mButtonData.size(); }
int Saveload::countButtonPage() const { return (int)mButtonPage.size(); }

//---------------------------------------------------------------------
// 
//  setter
// 
//
void Saveload::setMode(int aMode) { mMode = aMode; }
//---------------------------------------------------------------------
void Saveload::setScenarioId(int aId) { mScenarioId = aId; }


//---------------------------------------------------------------------
// 
//  getter
// 
//
int Saveload::mode() const { return mMode; }
//---------------------------------------------------------------------
const Button& Saveload::buttonData(int aIndex) const { return mButtonData[aIndex]; }
//---------------------------------------------------------------------
const Button& Saveload::buttonPage(int aIndex) const { return mButtonPage[aIndex]; }
//---------------------------------------------------------------------
const Button& Saveload::buttonBack() const { return mButtonBack; }
//---------------------------------------------------------------------
int Saveload::page() const { return mPage; }
//---------------------------------------------------------------------


} // namespace 