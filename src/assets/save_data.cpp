//---------------------------------------------------------------------
// 
//  
// 
//
#include "save_data.hpp"
#include "DxLib.h"

namespace osiv {

//---------------------------------------------------------------------
// 
//  
// 
//
SaveData::SaveData()
    : mScenarioId(-1)
    , mDay("----/--/--")
    , mTime("--:--")
{
}


//---------------------------------------------------------------------
// 
//  setter
// 
//
void SaveData::setScenarioId(int aId) { mScenarioId = aId; }
void SaveData::setDay(std::string aDay) { mDay = aDay; }
void SaveData::setTime(std::string aTime) { mTime = aTime; }

//---------------------------------------------------------------------
// 
//  getter
// 
//
int SaveData::scenarioId() const { return mScenarioId; }
std::string SaveData::day() const { return mDay; }
std::string SaveData::time() const { return mTime; }

} // namespace