//---------------------------------------------------------------------
// 
//  
// 
//
#pragma once
#include <vector>
#include "title/title.hpp"

namespace osiv {

//---------------------------------------------------------------------
// 
//  
// 
//
class SceneManager {
public:
    static const int SCENE_TITLE = 0;    // タイトル画面
    static const int SCENE_GAME = 1;     // ゲーム画面
    static const int SCENE_SAVE = 2;     // セーブ画面
    static const int SCENE_LOAD = 3;     // ロード画面
    static const int SCENE_BACKLOG = 4;  // バックログ画面
    static const int SCENE_CONFIG = 5;   // コンフィグ画面

    ///
    static SceneManager& ins();

    //----- 初期化処理
    int initialize();    // ゲーム情報を初期化します。

    //----- 更新処理
    int update();

    /// シーン変更開始
    void change(int aScene);   // シーンの変更
    void changePrevScene();    // 前のシーンに戻る

    void startFadeOut();       // フェードアウト開始
    void startFadeIn();        // フェードイン開始

    void startNextScene();     // 次のシーン

    /// 状態確認
    bool isChangeable() const;  // シーン変更可能か
    bool isChangeNow() const;   // シーン変更中か


    /// setter
    void setParam1(int aParam);
    void setFadeSpeed(int aSpeed);

    /// getter
    int scene() const;
    int alpha() const;
    int nextScene() const;
    int param1() const;

private:
    SceneManager();

    /// member
    int mScene;          // シーン
    int mNextScene;      // 次のシーン
    int mPrevScene;      // 前のシーン
    bool mChangeFlag;    // チェンジ中か
    bool mFadeOutFlag;   // フェードアウトのフラグ
    bool mFadeInFlag;    // フェードインのフラグ
    int mAlpha;          // 画面透明度（0：黒～255：透明）
    int mParam1;         // 引数1
    int mFadeSpeed;      // フェード速度
};

}