//---------------------------------------------------------------------
// 
//  
// 
//
#pragma once
#include <vector>
#include <string>
#include "assets/data.hpp"
#include "util/button.hpp"

namespace osiv {
//---------------------------------------------------------------------
// 
//  
// 
//
class Game {
public:
    /// コンストラクタ
    Game();

    /// 初期化処理
    void initialize();

    /// 更新処理
    void update();
    void updateScenario(); // シナリオ状態更新
    
    /// キー操作
    void keyProcess();

    /// クリック操作
    void clickProcess();
    void clickProcessLeft();  // 左クリックの処理
    void clickProcessRight(); // 右クリックの処理


    /// 次の文字へ
    void nextWord();

    /// テキストをフルオープン
    void fullOpen();

    /// 次のシナリオへ
    void nextScenario(bool aJumpFlag = false);

    /// テキストがすべて表示済か
    bool isFullOpen() const;

    /// 指定のシナリオにジャンプ
    void jumpScenario(int aId);

    /// setter
    void setAutoFlag(bool aFlag);

    /// getter
    const ScenarioData& scenario() const;
    std::string scenarioText() const;
    int scenarioId() const;
    std::string text1() const;  // 1行目のテキスト
    std::string text2() const;  // 2行目のテキスト
    std::string text3() const;  // 3行目のテキスト
    bool autoFlag() const;
    bool hideFlag() const;
    const Button& buttonAuto() const;
    const Button& buttonSkip() const;
    const Button& buttonLog() const;
    const Button& buttonConf() const;
    const Button& buttonSave() const;
    const Button& buttonLoad() const;
    const Button& buttonClose() const;
    int buttonAutoIndex() const;
    int buttonSkipIndex() const;
    int buttonLogIndex() const;
    int buttonConfIndex() const;
    int buttonSaveIndex() const;
    int buttonLoadIndex() const;
    int buttonCloseIndex() const;
    int frame() const;

private:
    int mScenarioId;       // シナリオID
    int mTextLength;       // 全体の文字数
    int mTextLength1;      // 1行目の文字数
    int mTextLength2;      // 2行目の文字数
    int mTextLength3;      // 3行目の文字数
    int mTextLengthMax;    // 1行の表示最大数

    bool mAutoFlag;        // オートフラグ
    bool mSkipFlag;        // スキップフラグ
    bool mHideFlag;        // ウインドウ非表示フラグ
    bool mFadeFlag;        // フェードフラグ

    int mFrame;            // ゲーム全体の経過フレーム数
    int mScenarioFrame;    // シナリオ開始からのフレーム数
    int mFulOpenFrame;     // フルオープン後のフレーム数
    int mFadeFrame;        // フェードのフレーム数

    // 表示キャラ

    //----- UIボタン
    Button mButtonAuto;     // オートボタン
    Button mButtonSkip;     // スキップボタン
    Button mButtonLog;      // ログボタン
    Button mButtonConf;     // 設定ボタン
    Button mButtonSave;     // セーブボタン
    Button mButtonLoad;     // ロードボタン
    Button mButtonClose;    // 閉じるボタン
};

}