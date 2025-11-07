//---------------------------------------------------------------------
// 
//  
// 
//
#include "game_render.hpp"
#include "DxLib.h"
#include "system/system.hpp"
#include "assets/images.hpp"
#include "assets/data.hpp"
#include "system/scene_manager.hpp"

namespace osiv {

//---------------------------------------------------------------------
// 
//  コンストラクタ
// 
//
GameRender::GameRender()
{
}

//---------------------------------------------------------------------
// 
//  描画処理
// 
//
void GameRender::render(const Game& aGame) const
{
    //----- 背景の描画
    renderBack(aGame);

    //----- キャラクターの描画
    renderChara(aGame);

    //----- UIの描画
    renderTextwindow(aGame);
}

//---------------------------------------------------------------------
// 
//  背景の描画処理
// 
//
void GameRender::renderBack(const Game& aGame) const
{
    int id = aGame.scenarioId();
    int image = Data::ins().scenario(id).back();
    DxLib::DrawGraph(0, 0, Images::ins().back(image), TRUE);

    if (image == 1) {
        int frame = aGame.frame();
        int dy = frame % 400;
        if (dy >= 100 && dy < 200) {
            dy = 200 - dy;
        }
        if (dy >= 200 && dy < 300) {
            dy = 200 - dy;
        }
        if (dy >= 300 && dy < 400) {
            dy = dy - 400;
        }
        DxLib::DrawGraph(370, 200 + dy, Images::ins().nowloadingText(), TRUE);
    }
}

//---------------------------------------------------------------------
// 
//  キャラの描画処理
// 
//
void GameRender::renderChara(const Game& aGame) const
{
    //int posX = 400;
    //int posY = 100;
    //int sizeX = 1000;
    //int sizeY = 1480;

    int id = aGame.scenarioId();
    int chara1Id = Data::ins().scenario(id).chara1Id();
    int chara2Id = Data::ins().scenario(id).chara2Id();
    int chara3Id = Data::ins().scenario(id).chara3Id();
    int chara1Face = Data::ins().scenario(id).chara1Face();
    int chara2Face = Data::ins().scenario(id).chara2Face();
    int chara3Face = Data::ins().scenario(id).chara3Face();

    if (chara1Id >= 0) {
        int image = Images::ins().chara(chara1Id, chara1Face);
        int posX = 600;
        int posY = 50;
        int sizeX = 750;
        int sizeY = 1110;

        DxLib::DrawExtendGraph(
            posX,
            posY,
            posX + sizeX,
            posY + sizeY,
            image,
            TRUE);
    }
}

//---------------------------------------------------------------------
// 
//  テキストウインドウの描画処理
// 
//
void GameRender::renderTextwindow(const Game& aGame) const
{
    //----- テキストウインドウ非表示中なら表示しない
    if (aGame.hideFlag()) {
        return;
    }

    //----- テキストウインドウ
    DxLib::DrawGraph(
        0,
        System::ins().windowSizeY() - 200,
        Images::ins().textwindow(),
        TRUE);

    //----- テキスト
    int font = Data::ins().font(0);
    int fontColor = Data::ins().fontColor(0);
    int id = aGame.scenarioId();
    // 名前
    std::string name = Data::ins().scenario(id).name();
    DrawFormatStringToHandle(250, System::ins().windowSizeY() - 200 + 30, fontColor, font, "%s", name.c_str());
    // セリフ
    DrawFormatStringToHandle(300, System::ins().windowSizeY() - 200 + 70, fontColor, font, "%s", aGame.text1().c_str());
    DrawFormatStringToHandle(300, System::ins().windowSizeY() - 200 + 105, fontColor, font, "%s", aGame.text2().c_str());
    DrawFormatStringToHandle(300, System::ins().windowSizeY() - 200 + 140, fontColor, font, "%s", aGame.text3().c_str());

    //----- ボタン
    DxLib::DrawGraph(
        aGame.buttonAuto().posX(),
        aGame.buttonAuto().posY(),
        Images::ins().buttonAuto(aGame.buttonAutoIndex()),
        TRUE);
    DxLib::DrawGraph(
        aGame.buttonSkip().posX(),
        aGame.buttonSkip().posY(),
        Images::ins().buttonSkip(aGame.buttonSkipIndex()),
        TRUE);
    DxLib::DrawGraph(
        aGame.buttonLog().posX(),
        aGame.buttonLog().posY(),
        Images::ins().buttonLog(aGame.buttonLogIndex()),
        TRUE);
    DxLib::DrawGraph(
        aGame.buttonConf().posX(),
        aGame.buttonConf().posY(),
        Images::ins().buttonConf(aGame.buttonConfIndex()),
        TRUE);
    DxLib::DrawGraph(
        aGame.buttonSave().posX(),
        aGame.buttonSave().posY(),
        Images::ins().buttonSave(aGame.buttonSaveIndex()),
        TRUE);
    DxLib::DrawGraph(
        aGame.buttonLoad().posX(),
        aGame.buttonLoad().posY(),
        Images::ins().buttonLoad(aGame.buttonLoadIndex()),
        TRUE);
    // 閉じるボタン
    DxLib::DrawGraph(
        aGame.buttonClose().posX(),
        aGame.buttonClose().posY(),
        Images::ins().buttonClose(aGame.buttonCloseIndex()),
        TRUE);
    // ボリュームボタン
}



} // namespace 