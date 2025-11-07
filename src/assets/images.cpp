//---------------------------------------------------------------------
// 
//  
// 
//
#include "images.hpp"
#include "DxLib.h"

namespace osiv {

//---------------------------------------------------------------------
// 
//  
// 
//
Images::Images()
    : mTitleBack()
    , mTitleButton()
    , mBack()
    , mChara()
    , mTextwindow()
    , mButtonAuto()
    , mButtonSkip()
    , mButtonLog()
    , mButtonConf()
    , mButtonSave()
    , mButtonLoad()
    , mButtonClose()
    , mNowloadingText()
    , mNowloadingBar()
    , mBacklogWindow()
    , mBacklogButtonBack()
    , mBacklogScrollbar()
    , mBacklogScrollbox()
    , mSaveloadBack()
    , mSaveloadBase()
    , mSaveloadPage()
    , mSaveloadButtonBack()
    , mSaveloadButtonDelete()
    , mSaveloadLogoLoad()
    , mSaveloadLogoSave()
    , mSaveloadThumbnailNodata()
{
}

//---------------------------------------------------------------------
// 
//  
// 
//
Images& Images::ins()
{
    static Images instance;
    return instance;
}

//---------------------------------------------------------------------
// 
//  
// 
//
void Images::load()
{

    //-----
    char url[100];

    //----- タイトル画面
    mTitleBack = LoadGraph("assets/images/title/title_back.png");
    mTitleButton.resize(8);
    sprintf_s(url, "assets/images/title/title_button.png");
    DxLib::LoadDivGraph(url, 8, 4, 2, 200, 40, mTitleButton.data());

    //----- ゲーム画面
    // 背景
    int backNum = 20;
    mBack.resize(backNum);
    mBack[0] = DxLib::LoadGraph("assets/images/back0.png");
    mBack[1] = DxLib::LoadGraph("assets/images/back1.png");
    mBack[2] = DxLib::LoadGraph("assets/images/back2.png");
    mBack[3] = DxLib::LoadGraph("assets/images/back3.png");

    // キャラクター
    int charaNum = 20;
    mChara.resize(charaNum);
    mChara[0].resize(4);
    mChara[0][0] = DxLib::LoadGraph("assets/images/chara0_0.png");
    mChara[0][1] = DxLib::LoadGraph("assets/images/chara0_1.png");
    mChara[0][2] = DxLib::LoadGraph("assets/images/chara0_2.png");
    mChara[0][3] = DxLib::LoadGraph("assets/images/chara0_3.png");

    // テキストウインドウ
    mTextwindow = DxLib::LoadGraph("assets/images/textwindow.png");

    mButtonAuto.resize(3);
    sprintf_s(url, "assets/images/button_auto.png");
    DxLib::LoadDivGraph(url, 3, 3, 1, 49, 44, mButtonAuto.data());

    mButtonSkip.resize(3);
    sprintf_s(url, "assets/images/button_skip.png");
    DxLib::LoadDivGraph(url, 3, 3, 1, 49, 44, mButtonSkip.data());

    mButtonLog.resize(3);
    sprintf_s(url, "assets/images/button_log.png");
    DxLib::LoadDivGraph(url, 3, 3, 1, 49, 44, mButtonLog.data());

    mButtonConf.resize(3);
    sprintf_s(url, "assets/images/button_conf.png");
    DxLib::LoadDivGraph(url, 3, 3, 1, 49, 44, mButtonConf.data());

    mButtonSave.resize(3);
    sprintf_s(url, "assets/images/button_save.png");
    DxLib::LoadDivGraph(url, 3, 3, 1, 49, 44, mButtonSave.data());

    mButtonLoad.resize(3);
    sprintf_s(url, "assets/images/button_load.png");
    DxLib::LoadDivGraph(url, 3, 3, 1, 49, 44, mButtonLoad.data());

    mButtonClose.resize(3);
    sprintf_s(url, "assets/images/button_close.png");
    DxLib::LoadDivGraph(url, 3, 3, 1, 25, 25, mButtonClose.data());

    // ナウローディング
    mNowloadingText = DxLib::LoadGraph("assets/images/nowloading_text.png");
    mNowloadingBar = DxLib::LoadGraph("assets/images/nowloading_bar.png");

    //----- バックログ画面
    mBacklogWindow = DxLib::LoadGraph("assets/images/backlog/window.png");

    mBacklogButtonBack.resize(2);
    sprintf_s(url, "assets/images/backlog/button_back.png");
    DxLib::LoadDivGraph(url, 2, 2, 1, 100, 80, mBacklogButtonBack.data());

    mBacklogScrollbar = DxLib::LoadGraph("assets/images/backlog/scrollbar.png");
    mBacklogScrollbox = DxLib::LoadGraph("assets/images/backlog/scrollbox.png");

    //----- セーブロード画面
    mSaveloadBack = DxLib::LoadGraph("assets/images/saveload/back.png");

    mSaveloadBase.resize(2);
    sprintf_s(url, "assets/images/saveload/base.png");
    DxLib::LoadDivGraph(url, 2, 1, 2, 514, 114, mSaveloadBase.data());

    mSaveloadPage.resize(40);
    sprintf_s(url, "assets/images/saveload/button_page.png");
    DxLib::LoadDivGraph(url, 40, 20, 2, 40, 40, mSaveloadPage.data());

    mSaveloadButtonBack.resize(2);
    sprintf_s(url, "assets/images/saveload/button_back.png");
    DxLib::LoadDivGraph(url, 2, 2, 1, 100, 80, mSaveloadButtonBack.data());

    mSaveloadButtonDelete.resize(2);
    sprintf_s(url, "assets/images/saveload/button_delete.png");
    DxLib::LoadDivGraph(url, 2, 2, 1, 25, 25, mSaveloadButtonDelete.data());

    mSaveloadLogoLoad = DxLib::LoadGraph("assets/images/saveload/load_logo.png");
    mSaveloadLogoSave = DxLib::LoadGraph("assets/images/saveload/save_logo.png");
    mSaveloadThumbnailNodata = DxLib::LoadGraph("assets/images/saveload/thumbnail_nodata.png");
}

//---------------------------------------------------------------------
// 
//  getter
// 
//
int Images::titleBack() const { return mTitleBack; }
//---------------------------------------------------------------------
int Images::titleButton(int aKind, int aIndex) const { return mTitleButton[aIndex * 4 + aKind]; }
//---------------------------------------------------------------------
int Images::back(int aBackId) const { return mBack[aBackId]; }
//---------------------------------------------------------------------
int Images::chara(int aCharaId, int aIndex) const { return mChara[aCharaId][aIndex]; }
//---------------------------------------------------------------------
int Images::textwindow() const { return mTextwindow; }
//---------------------------------------------------------------------
int Images::buttonAuto(int aIndex) const { return mButtonAuto[aIndex]; }
//---------------------------------------------------------------------
int Images::buttonSkip(int aIndex) const { return mButtonSkip[aIndex]; }
//---------------------------------------------------------------------
int Images::buttonLog(int aIndex) const { return mButtonLog[aIndex]; }
//---------------------------------------------------------------------
int Images::buttonConf(int aIndex) const { return mButtonConf[aIndex]; }
//---------------------------------------------------------------------
int Images::buttonSave(int aIndex) const { return mButtonSave[aIndex]; }
//---------------------------------------------------------------------
int Images::buttonLoad(int aIndex) const { return mButtonLoad[aIndex]; }
//---------------------------------------------------------------------
int Images::buttonClose(int aIndex) const { return mButtonClose[aIndex]; }
//---------------------------------------------------------------------
int Images::nowloadingText() const { return mNowloadingText; }
//---------------------------------------------------------------------
int Images::nowloadingBar() const { return mNowloadingBar; }
//---------------------------------------------------------------------
int Images::backlogWindow() const { return mBacklogWindow; }
//---------------------------------------------------------------------
int Images::backlogButtonBack(int aIndex) const { return mBacklogButtonBack[aIndex]; }
//---------------------------------------------------------------------
int Images::backlogScrollbar() const { return mBacklogScrollbar; }
//---------------------------------------------------------------------
int Images::backlogScrollbox() const { return mBacklogScrollbox; }
//---------------------------------------------------------------------
int Images::saveloadBack() const { return mSaveloadBack; }
//---------------------------------------------------------------------
int Images::saveloadBase(int aIndex) const { return mSaveloadBase[aIndex]; }
//---------------------------------------------------------------------
int Images::saveloadPage(int aNum, int aIndex) const { return mSaveloadPage[aNum + aIndex * 20]; }
//---------------------------------------------------------------------
int Images::saveloadButtonBack(int aIndex) const { return mSaveloadButtonBack[aIndex]; }
//---------------------------------------------------------------------
int Images::saveloadButtonDelete(int aIndex) const { return mSaveloadButtonDelete[aIndex]; }
//---------------------------------------------------------------------
int Images::saveloadLogoLoad() const { return mSaveloadLogoLoad; }
//---------------------------------------------------------------------
int Images::saveloadLogoSave() const { return mSaveloadLogoSave; }
//---------------------------------------------------------------------
int Images::saveloadThumbnailNodata() const { return mSaveloadThumbnailNodata; }
//---------------------------------------------------------------------

} // namespace pokehito