//---------------------------------------------------------------------
// 
//  
// 
//
#include "assets_manager.hpp"
#include "DxLib.h"
#include "assets/Images.hpp"
#include "assets/Data.hpp"

namespace osiv {

//---------------------------------------------------------------------
// 
//  
// 
//
AssetsManager::AssetsManager()
{

}


//---------------------------------------------------------------------
// 
//  
// 
//
AssetsManager& AssetsManager::ins()
{
    static AssetsManager instance;
    return instance;
}

//---------------------------------------------------------------------
// 
//  
// 
//
void AssetsManager::load()
{
    //----- ƒf[ƒ^“Ç‚İ
    Data::ins().load();

    //----- ‰æ‘œ“Ç‚İ
    Images::ins().load();
}

}