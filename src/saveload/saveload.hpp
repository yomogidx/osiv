//---------------------------------------------------------------------
// 
//  
// 
//
#pragma once
#include <vector>
#include "util/button.hpp"

namespace osiv {

//---------------------------------------------------------------------
// 
//  
// 
//
class Saveload {
public:
    static const int MODE_SAVE = 0;
    static const int MODE_LOAD = 1;

    /// コンストラクタ
    Saveload();

    /// 初期化処理
    void initialize();

    /// 更新処理
    void update();

    /// キー操作
    void keyProcess();

    /// クリック操作
    void click();

    /// カウント
    int countButtonData() const;
    int countButtonPage() const;

    /// setter
    void setMode(int aMode);
    void setScenarioId(int aId);

    /// getter
    int mode() const;
    const Button& buttonData(int aIndex) const;
    const Button& buttonPage(int aIndex) const;
    const Button& buttonBack() const;
    int page() const;

private:
    int mMode;                        // モード
    std::vector<Button> mButtonData;  // セーブデータボタン
    std::vector<Button> mButtonPage;  // ページ番号ボタン
    Button mButtonBack;               // 戻るボタン
    int mPage;                        // 現在表示中のページ
    int mScenarioId;                  // シナリオID
};

}