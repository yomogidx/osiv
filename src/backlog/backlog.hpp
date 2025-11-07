//---------------------------------------------------------------------
// 
//  
// 
//
#pragma once
#include "util/button.hpp"

namespace osiv {

//---------------------------------------------------------------------
// 
//  
// 
//
class Backlog {
public:
    /// コンストラクタ
    Backlog();

    /// 初期化処理
    void initialize();

    /// 更新処理
    void update();

    /// キー操作
    void keyProcess();

    /// クリック操作
    void click();

    /// スクロール操作
    void scroll();

    /// スクロールバーのレート
    double scrollbarRate() const;

    /// setter
    void setScenarioId(int aId);
    void setScenarioIdMax(int aId);

    /// getter
    const Button& buttonBack() const;
    int id1() const;  // 1行目のID
    int id2() const;  // 2行目のID
    int id3() const;  // 3行目のID

private:
    Button mButtonBack;  // 戻るボタン
    int mScenarioId;     // 現在表示しているシナリオID
    int mScenarioIdMax;  // 表示最大（現在表示しているシナリオID）
    bool mScrollbarMove; // スクロールバー移動中フラグ
};

}