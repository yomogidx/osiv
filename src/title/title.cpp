//---------------------------------------------------------------------
// 
//  
// 
//
#include "title.hpp"
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
Title::Title()
{
}

//---------------------------------------------------------------------
// 
//  
// 
//
void Title::initialize()
{

}

//---------------------------------------------------------------------
// 
//  
// 
//
void Title::update()
{
    //----- キー操作
    keyProcess();

    //----- クリック処理
    click();

}


//---------------------------------------------------------------------
// 
//  キー操作
// 
//
void Title::keyProcess()
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
void Title::click()
{
    //----- 左クリック押下時
    if (Input::ins().leftClick() == 1) {
        SceneManager::ins().change(SceneManager::SCENE_GAME);
    }

    //----- 右クリック押下時
    if (Input::ins().rightClick() == 1) {

    }
}


//---------------------------------------------------------------------
// 
//  setter
// 
//

//---------------------------------------------------------------------
// 
//  getter
// 
//


} // namespace game