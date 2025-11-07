//---------------------------------------------------------------------
// 
//  
// 
//
#pragma once
#include <vector>

namespace osiv {

//---------------------------------------------------------------------
// 
//  
// 
//
class Images {
public:
    static Images& ins();
    void load();

    /// getter
    int titleBack() const;
    int titleButton(int aKind, int aIndex) const;
    int back(int aBackId) const;
    int chara(int aCharaId, int aIndex) const;
    int textwindow() const;
    int buttonAuto(int aIndex) const;
    int buttonSkip(int aIndex) const;
    int buttonLog(int aIndex) const;
    int buttonConf(int aIndex) const;
    int buttonSave(int aIndex) const;
    int buttonLoad(int aIndex) const;
    int buttonClose(int aIndex) const;
    int nowloadingText() const;
    int nowloadingBar() const;
    int backlogWindow() const;
    int backlogButtonBack(int aIndex) const;
    int backlogScrollbar() const;
    int backlogScrollbox() const;
    int saveloadBack() const;
    int saveloadBase(int aIndex) const;
    int saveloadPage(int aNum, int aIndex) const;
    int saveloadButtonBack(int aIndex) const;
    int saveloadButtonDelete(int aIndex) const;
    int saveloadLogoLoad() const;
    int saveloadLogoSave() const;
    int saveloadThumbnailNodata() const;

private:
    /// コンストラクタ
    Images();

    //----- タイトル画面
    int mTitleBack;
    std::vector<int> mTitleButton;

    //----- ゲーム画面
    std::vector<int> mBack;                // 背景
    std::vector<std::vector<int>> mChara;  // キャラクターの立ち絵
    int mTextwindow;                       // テキストウインドウ
    std::vector<int> mButtonAuto;   // オートボタン
    std::vector<int> mButtonSkip;   // スキップボタン
    std::vector<int> mButtonLog;    // ログボタン
    std::vector<int> mButtonConf;   // 設定ボタン
    std::vector<int> mButtonSave;   // セーブボタン
    std::vector<int> mButtonLoad;   // ロードボタン
    std::vector<int> mButtonClose;  // 閉じるボタン
    //ナウローディング
    int mNowloadingText;            // ナウローディング
    int mNowloadingBar;             // ナウローディング

    // バックログ画面
    int mBacklogWindow;             // 背景
    std::vector<int> mBacklogButtonBack;  // 戻るボタン
    int mBacklogScrollbar;  // 
    int mBacklogScrollbox;  // 
    // セーブロード画面
    int mSaveloadBack;
    std::vector<int> mSaveloadBase;        // ベース
    std::vector<int> mSaveloadPage;        // 番号ボタン
    std::vector<int> mSaveloadButtonBack;  // 戻るボタン
    std::vector<int> mSaveloadButtonDelete;// 削除ボタン
    int mSaveloadLogoLoad;
    int mSaveloadLogoSave;
    int mSaveloadThumbnailNodata;
};

}