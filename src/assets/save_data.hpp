//---------------------------------------------------------------------
// 
//  
// 
//
#pragma once
#include <string>

namespace osiv {

//---------------------------------------------------------------------
// 
//  
// 
//
class SaveData {
public:
    /// コンストラクタ
    SaveData();

    /// setter
    void setScenarioId(int aId);
    void setDay(std::string aDay);
    void setTime(std::string aTime);

    /// getter
    int scenarioId() const;
    std::string day() const;
    std::string time() const;

private:
    int mScenarioId;    // シナリオID
    std::string mDay;   // 保存日付
    std::string mTime;  // 保存時間
};

}