//---------------------------------------------------------------------
// 
//  
// 
//
#include "scenario_data.hpp"
#include "DxLib.h"
#include "util/util.hpp"

namespace osiv {

//---------------------------------------------------------------------
// 
//  コンストラクタ
// 
//
ScenarioData::ScenarioData()
    : mId(0)
    , mName("")
    , mText("")
    , mText1("")
    , mText2("")
    , mText3("")
    , mText1small("")
    , mText2small("")
    , mBack(0)
    , mChara1Id(-1)
    , mChara2Id(-1)
    , mChara3Id(-1)
    , mChara1Face(-1)
    , mChara2Face(-1)
    , mChara3Face(-1)
    , mFade(-1)
{
}

//---------------------------------------------------------------------
// 
//  setter
// 
//
void ScenarioData::setId(int aId) { mId = aId; }
//---------------------------------------------------------------------
void ScenarioData::setName(std::string aName) { mName = aName; }
//---------------------------------------------------------------------
void ScenarioData::setText(std::string aText)
{
    mText = aText;

    int length = 0;
    int lengthMax = textLength();
    int length1 = 0;
    int length2 = 0;
    int length3 = 0;
    int length1small = 0;
    int length2small = 0;
    int length3small = 0;
    
    while (length < lengthMax) {
        length += Util::isJapaneseCharacter(mText[length]);
        if (length <= 50) {
            length1 = length;
        }
        else if (length <= 100) {
            length2 = length - length1;
        }
        else {
            length3 = length - length1 - length2;
        }

        if (length <= 38) {
            length1small = length;
        }
        else if (length <= 74) {
            length2small = length - length1small;
        }
        else {
            length3small = 1;
        }
    }

    if (length1 > 0) { mText1 = mText.substr(0, length1); }
    if (length2 > 0) { mText2 = mText.substr(length1, length2); }
    if (length3 > 0) { mText3 = mText.substr(length1 + length2, length3); }

    if (length1small > 0) { mText1small = mText.substr(0, length1small); }
    if (length2small > 0) { mText2small = mText.substr(length1small, length2small); }
    if (length3small > 0) { mText2small += "…"; }
}
//---------------------------------------------------------------------
void ScenarioData::setBack(int aId) { mBack = aId; }
//---------------------------------------------------------------------
void ScenarioData::setChara1Id(int aId) { mChara1Id = aId; }
//---------------------------------------------------------------------
void ScenarioData::setChara1Face(int aId) { mChara1Face = aId; }
//---------------------------------------------------------------------
void ScenarioData::setChara2Id(int aId) { mChara2Id = aId; }
//---------------------------------------------------------------------
void ScenarioData::setChara2Face(int aId) { mChara2Face = aId; }
//---------------------------------------------------------------------
void ScenarioData::setChara3Id(int aId) { mChara3Id = aId; }
//---------------------------------------------------------------------
void ScenarioData::setChara3Face(int aId) { mChara3Face = aId; }
//---------------------------------------------------------------------
void ScenarioData::setFade(int aFadeKind) { mFade = aFadeKind; }
//---------------------------------------------------------------------


//---------------------------------------------------------------------
// 
//  getter
// 
//
int ScenarioData::id() const { return mId; }
//---------------------------------------------------------------------
std::string ScenarioData::name() const { return mName; }
//---------------------------------------------------------------------
std::string ScenarioData::text() const { return mText; }
//---------------------------------------------------------------------
int ScenarioData::textLength() const { return (int)mText.length(); }
//---------------------------------------------------------------------
std::string ScenarioData::text1() const { return mText1; }
//---------------------------------------------------------------------
std::string ScenarioData::text2() const { return mText2; }
//---------------------------------------------------------------------
std::string ScenarioData::text3() const { return mText3; }
//---------------------------------------------------------------------
std::string ScenarioData::text1small() const { return mText1small; }
//---------------------------------------------------------------------
std::string ScenarioData::text2small() const { return mText2small; }
//---------------------------------------------------------------------
int ScenarioData::back() const { return mBack; }
//---------------------------------------------------------------------
int ScenarioData::chara1Id() const { return mChara1Id; }
//---------------------------------------------------------------------
int ScenarioData::chara2Id() const { return mChara2Id; }
//---------------------------------------------------------------------
int ScenarioData::chara3Id() const { return mChara3Id; }
//---------------------------------------------------------------------
int ScenarioData::chara1Face() const { return mChara1Face; }
//---------------------------------------------------------------------
int ScenarioData::chara2Face() const { return mChara2Face; }
//---------------------------------------------------------------------
int ScenarioData::chara3Face() const { return mChara3Face; }
//---------------------------------------------------------------------
int ScenarioData::fade() const { return mFade; }
//---------------------------------------------------------------------

} // namespace 