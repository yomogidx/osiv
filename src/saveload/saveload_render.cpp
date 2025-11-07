//---------------------------------------------------------------------
// 
//  
// 
//
#include "saveload_render.hpp"
#include "DxLib.h"
#include "system/system.hpp"
#include "assets/images.hpp"
#include "assets/data.hpp"

namespace osiv {

//---------------------------------------------------------------------
// 
//  コンストラクタ
// 
//
SaveloadRender::SaveloadRender()
{
}

//---------------------------------------------------------------------
// 
//  描画処理
// 
//
void SaveloadRender::render(const Saveload& aSaveload) const
{
    //----- 背景
    DxLib::DrawGraph(0, 0, Images::ins().saveloadBack(), TRUE);

    //----- ロゴ
    if (aSaveload.mode() == Saveload::MODE_SAVE) {
        DxLib::DrawGraph(25, 25, Images::ins().saveloadLogoSave(), TRUE);
    }
    else {
        DxLib::DrawGraph(25, 25, Images::ins().saveloadLogoLoad(), TRUE);
    }

    //----- セーブデータ
    int n = aSaveload.countButtonData();
    for (int i = 0; i < n; i++) {
        // ベース
        int baseImage = aSaveload.buttonData(i).imageIndex();
        DxLib::DrawGraph(
            aSaveload.buttonData(i).posX(),
            aSaveload.buttonData(i).posY(),
            Images::ins().saveloadBase(baseImage),
            TRUE);

        // 日付
        int num = i + aSaveload.page() * 10;
        int font = Data::ins().font(1);
        int fontColor = Data::ins().fontColor(1);
        DrawFormatStringToHandle(
            aSaveload.buttonData(i).posX() + 370,
            aSaveload.buttonData(i).posY() + 90,
            fontColor,
            font,
            "%s %s",
            Data::ins().saveData(num).day().c_str(),
            Data::ins().saveData(num).time().c_str());

        // テキスト
        int id = Data::ins().saveData(num).scenarioId();
        if (id < 0) {
            // サムネイル
            DxLib::DrawGraph(
                aSaveload.buttonData(i).posX() + 7,
                aSaveload.buttonData(i).posY() + 7,
                Images::ins().saveloadThumbnailNodata(),
                TRUE);
        }
        else {
            //----- サムネイル
            // 背景
            int imageBack = Data::ins().scenario(id).back();
            DrawExtendGraph(
                aSaveload.buttonData(i).posX() + 7,
                aSaveload.buttonData(i).posY() + 7,
                aSaveload.buttonData(i).posX() + 184,
                aSaveload.buttonData(i).posY() + 107,
                Images::ins().back(imageBack),
                TRUE);
            
            // 1行目
            DrawFormatStringToHandle(
                aSaveload.buttonData(i).posX() + 195,
                aSaveload.buttonData(i).posY() + 37,
                fontColor,
                font,
                "%s",
                Data::ins().scenario(id).text1small().c_str());
            // 2行目
            DrawFormatStringToHandle(
                aSaveload.buttonData(i).posX() + 195,
                aSaveload.buttonData(i).posY() + 57,
                fontColor,
                font,
                "%s",
                Data::ins().scenario(id).text2small().c_str());
        }
    }
    


    //----- ページボタン
    n = aSaveload.countButtonPage();
    for (int i = 0; i < n; i++) {
        int image = aSaveload.buttonPage(i).imageIndex();
        image = (aSaveload.page() == i) ? 1 : image;
        DxLib::DrawGraph(
            aSaveload.buttonPage(i).posX(),
            aSaveload.buttonPage(i).posY(),
            Images::ins().saveloadPage(i, image),
            TRUE);
    }

    //----- 戻るボタン
    int image = aSaveload.buttonBack().imageIndex();
    DxLib::DrawGraph(
        aSaveload.buttonBack().posX(),
        aSaveload.buttonBack().posY(),
        Images::ins().saveloadButtonBack(image),
        TRUE);
}


} // namespace 