//---------------------------------------------------------------------
// 
//  
// 
//
#include "title_render.hpp"
#include "DxLib.h"
#include "system/system.hpp"
#include "assets/images.hpp"

namespace osiv {

//---------------------------------------------------------------------
// 
//  
// 
//
TitleRender::TitleRender()
{
}

//---------------------------------------------------------------------
// 
//  
// 
//
void TitleRender::render(const Title& aTitle) const
{
    //----- ”wŒi
    DxLib::DrawGraph(0, 0, Images::ins().titleBack(), TRUE);
    
    //----- ƒ{ƒ^ƒ“
    int basePosX = 300;
    int basePosY = 500;

    DxLib::DrawGraph(basePosX, basePosY, Images::ins().titleButton(0, 0), TRUE);
    DxLib::DrawGraph(basePosX, basePosY + 50, Images::ins().titleButton(1, 0), TRUE);
    DxLib::DrawGraph(basePosX, basePosY + 100, Images::ins().titleButton(2, 0), TRUE);
    DxLib::DrawGraph(basePosX, basePosY + 150, Images::ins().titleButton(3, 0), TRUE);

}

} // namespace 