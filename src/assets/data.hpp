//---------------------------------------------------------------------
// 
//  
// 
//
#pragma once
#include <vector>
#include "assets/scenario_data.hpp"
#include "assets/save_data.hpp"

namespace osiv {

//---------------------------------------------------------------------
// 
//  
// 
//
class Data {
public:
    /// シングルトン
    static Data& ins();

    /// ロード
    void load();

    /// セーブ
    void save(int aIndex, int aScenarioId);

    /// getter
    int font(int aId);
    int fontColor(int aId);
    const ScenarioData& scenario(int aId) const;
    const SaveData& saveData(int aNum) const;

private:
    /// コンストラクタ
    Data();

    /// セーブ
    void save();

    // ロード
    void loadScenario();  // シナリオデータの読込み
    void loadSaveData();  // セーブデータの読込み

    /// シナリオの追加
    void addScenario(
        std::string aName,
        std::string aText,
        int aBack=0,
        int aChara1=-1,
        int aChara2=-1,
        int aChara3=-1);

    void addScenarioFade(int aFadeKind);

    /// フォントデータ
    std::vector<int> mFont;
    std::vector<int> mFontColor;

    /// シナリオデータ
    std::vector<ScenarioData> mScenario;

    /// セーブデータ
    std::vector<SaveData> mSaveData;
};

} // namespace pokehito