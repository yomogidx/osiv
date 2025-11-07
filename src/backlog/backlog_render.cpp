//---------------------------------------------------------------------
// 
//  
// 
//
#include "backlog_render.hpp"
#include "DxLib.h"
#include "system/system.hpp"
#include "assets/images.hpp"
#include "assets/data.hpp"

namespace osiv {

//---------------------------------------------------------------------
// 
//  
// 
//
BacklogRender::BacklogRender()
{
}

//---------------------------------------------------------------------
// 
//  
// 
//
void BacklogRender::render(const Backlog& aBacklog) const
{
    //----- 背景
    DxLib::DrawGraph(0, 0, Images::ins().backlogWindow(), TRUE);

    //----- ボタン
    int image = aBacklog.buttonBack().imageIndex();
    DxLib::DrawGraph(1150, 600, Images::ins().backlogButtonBack(image), TRUE);

    //----- スクロールバー
    double rate = aBacklog.scrollbarRate();
    DxLib::DrawGraph(1150, 80, Images::ins().backlogScrollbar(), TRUE);
    DxLib::DrawGraph(1150, 80 + (int)(460 * rate), Images::ins().backlogScrollbox(), TRUE);


    //----- テキストの描画
    // 1
    // 2
    // 3
    
    // 1
    // 2

    // 1
    int font = Data::ins().font(0);
    int fontColor = Data::ins().fontColor(0);
    //----- 1行目
    int id1 = aBacklog.id1();
    if (id1 >= 0) {
        DrawFormatStringToHandle(250, 100, fontColor, font, "%s", Data::ins().scenario(id1).name().c_str());
        DrawFormatStringToHandle(300, 140, fontColor, font, "%s", Data::ins().scenario(id1).text1().c_str());
        DrawFormatStringToHandle(300, 175, fontColor, font, "%s", Data::ins().scenario(id1).text2().c_str());
        DrawFormatStringToHandle(300, 210, fontColor, font, "%s", Data::ins().scenario(id1).text3().c_str());
    }

    //----- 2行目
    int id2 = aBacklog.id2();
    if (id2 >= 0) {
        DrawFormatStringToHandle(250, 300, fontColor, font, "%s", Data::ins().scenario(id2).name().c_str());
        DrawFormatStringToHandle(300, 340, fontColor, font, "%s", Data::ins().scenario(id2).text1().c_str());
        DrawFormatStringToHandle(300, 375, fontColor, font, "%s", Data::ins().scenario(id2).text2().c_str());
        DrawFormatStringToHandle(300, 410, fontColor, font, "%s", Data::ins().scenario(id2).text3().c_str());
    }

    //---- 3行目
    int id3 = aBacklog.id3();
    if (id3 >= 0) {
        DrawFormatStringToHandle(250, 500, fontColor, font, "%s", Data::ins().scenario(id3).name().c_str());
        DrawFormatStringToHandle(300, 540, fontColor, font, "%s", Data::ins().scenario(id3).text1().c_str());
        DrawFormatStringToHandle(300, 575, fontColor, font, "%s", Data::ins().scenario(id3).text2().c_str());
        DrawFormatStringToHandle(300, 610, fontColor, font, "%s", Data::ins().scenario(id3).text3().c_str());
    }
}

//---------------------------------------------------------------------
// 
//  setter
// 
//



} // namespace 