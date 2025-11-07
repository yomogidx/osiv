//---------------------------------------------------------------------
// 
//  
// 
//
#include "Data.hpp"
#include "DxLib.h"
#include <fstream>
#include <iostream>
#include <sstream>

namespace osiv {

//---------------------------------------------------------------------
// 
//  
// 
//
Data::Data()
    : mFont()
    , mFontColor()
    , mScenario()
{
}

//---------------------------------------------------------------------
// 
//  
// 
//
Data& Data::ins()
{
    static Data instance;
    return instance;
}

//---------------------------------------------------------------------
// 
//  
// 
//
void Data::save()
{
    FILE* fp;
    errno_t error = fopen_s(&fp, "savedata/savedata.dat", "wb");

    if (fp == NULL) { // NULLが返ってきたらエラー発生
        puts("Fail data save");
        return;
    }
    for (int i = 0; i < 200; i++) {
        if (mSaveData[i].scenarioId() >= 0) {
            fprintf(fp, "%d %d %s %s\r\n",
                i,
                mSaveData[i].scenarioId(),
                mSaveData[i].day().c_str(),
                mSaveData[i].time().c_str());
        }
    }
    fclose(fp);
    puts("Success data save");
}

//---------------------------------------------------------------------
// 
//  
// 
//
void Data::save(int aIndex, int aScenarioId)
{
    //----- 
    mSaveData[aIndex].setScenarioId(aScenarioId);

    //---- 
    char c[256];
    DxLib::DATEDATA date;
    DxLib::GetDateTime(&date);
    std::stringstream ds;

    sprintf_s(c, "%02d", date.Year);
    ds << c << "/";
    sprintf_s(c, "%02d", date.Mon);
    ds << c << "/";
    sprintf_s(c, "%02d", date.Day);
    ds << c;
    mSaveData[aIndex].setDay(ds.str());

    //---- 
    ds.str("");
    sprintf_s(c, "%02d", date.Hour);
    ds << c << ":";
    sprintf_s(c, "%02d", date.Min);
    ds << c;
    mSaveData[aIndex].setTime(ds.str());

    //----
    save();
}

//---------------------------------------------------------------------
// 
//  
// 
//
void Data::load()
{
    //----- フォントデータの読込み
    mFont.resize(2);
    mFont[0] = DxLib::CreateFontToHandle("ＭＳ ゴシック", 28, 3, DX_FONTTYPE_ANTIALIASING_EDGE);
    mFont[1] = DxLib::CreateFontToHandle("ＭＳ ゴシック", 16, 3, DX_FONTTYPE_ANTIALIASING);

    //----- フォントカラーの読込み
    mFontColor.resize(2);
    mFontColor[0] = DxLib::GetColor(255, 255, 255);
    mFontColor[1] = DxLib::GetColor(63, 56, 51);

    //----- シナリオデータの読込み
    loadScenario();

    //----- セーブデータの読込み
    loadSaveData();
}

//---------------------------------------------------------------------
// 
//  シナリオデータの読込み
// 
//
void Data::loadScenario()
{
    addScenario("名前", "「あああああああ」", 1);
    addScenario("名前", "「いいいいいいい」", 1);
    addScenario("名前", "「ううううううう」", 1);
    addScenarioFade(0);
    addScenario("", "シーンチェンジ", 2, 0);
    addScenario("名前", "「表情1」", 2, 1);
    addScenario("名前", "「表情2」", 2, 2);
    addScenario("名前", "「表情3」", 2, 2);
    addScenario("名前", "「あああああああ」", 2);
    addScenario("名前", "「いいいいいいい」", 2);
    addScenario("名前", "「ううううううう」", 2);
    addScenario("名前", "「あああああああ」", 2);
    addScenario("名前", "「いいいいいいい」", 2);
    addScenario("名前", "「ううううううう」", 2);
    addScenario("名前", "「あああああああ」", 2);
    addScenario("名前", "「いいいいいいい」", 2);
    addScenario("名前", "「ううううううう」", 2);
    addScenario("名前", "「あああああああ」", 2);
    addScenario("名前", "「いいいいいいい」", 2);
    addScenario("名前", "「ううううううう」", 2);
    addScenarioFade(0);
    addScenario("名前", "「あああああああ」", 2);
    addScenario("名前", "「いいいいいいい」", 2);
    addScenario("名前", "「ううううううう」", 2);
    addScenario("名前", "「あああああああ」", 2);
    addScenario("名前", "「いいいいいいい」", 2);
    addScenario("名前", "「ううううううう」", 2);
    addScenario("", "");
    addScenario("", "");
    addScenario("", "");
    addScenario("", "");
    addScenario("", "");
    addScenario("", "");
    addScenario("", "");
    addScenario("", "");
    addScenario("", "");
    addScenario("", "");
    addScenario("", "");
    addScenario("", "");
    addScenario("", "");
    addScenario("", "");
    addScenario("", "");
    addScenario("", "");
    addScenario("", "");
    addScenario("", "");
    addScenario("", "");
    addScenario("", "");
    addScenario("", "");
    addScenario("", "");
    addScenario("", "");
    addScenario("", "");
    addScenario("", "");
    addScenario("", "");
    addScenario("", "");
    addScenario("", "");
    addScenario("", "");
    addScenario("", "");
    addScenario("", "");
    addScenario("", "");
    addScenario("", "");
    addScenario("", "");
    addScenario("", "");
    addScenario("", "");
    addScenario("", "");
    addScenario("", "");
    addScenario("", "");
    addScenario("", "");
    addScenario("", "");
    addScenario("", "");
    addScenario("", "");
    addScenario("", "");
    addScenario("", "");
}

//---------------------------------------------------------------------
// 
//  セーブデータの読込み
// 
//
void Data::loadSaveData()
{
    for (int i = 0; i < 200; i++) {
        SaveData s;
        mSaveData.push_back(s);
    }

    char str[1024];
    std::string s;
    std::stringstream ss;
    int num;

    int fp = FileRead_open("savedata/savedata.dat");
    if (fp == 0) {
        puts("Fail loading savedata file");
        return;
    }
    while (FileRead_gets(str, 256, fp) != -1) {
        ss.clear();
        ss.str(str);
        //---- 
        ss >> s;
        num = atoi(s.c_str());
        //---- 
        ss >> s;
        int id = atoi(s.c_str());
        mSaveData[num].setScenarioId(id);
        //---- 
        ss >> s;
        mSaveData[num].setDay(s);
        ss >> s;
        mSaveData[num].setTime(s);
    }
    FileRead_close(fp);
    puts("Success loading savedata file");
}

//---------------------------------------------------------------------
// 
//  
// 
//
void Data::addScenario(
    std::string aName,
    std::string aText,
    int aBack,
    int aChara1,
    int aChara2,
    int aChara3)
{
    ScenarioData s;
    s.setId((int)mScenario.size());
    s.setName(aName);
    s.setText(aText);
    s.setBack(aBack);
    if (aChara1 >= 0) {
        s.setChara1Id((int)(aChara1 / 10));
        s.setChara1Face((int)(aChara1 % 10));
    }

    mScenario.push_back(s);
}

//---------------------------------------------------------------------
// 
//  フェードアウト
// 
//
void Data::addScenarioFade(int aFadeKind)
{
    int index = (int)mScenario.size() - 1;
    mScenario[index].setFade(0);
}

//---------------------------------------------------------------------
// 
//  getter
// 
//
int Data::font(int aId) { return mFont[aId]; }
int Data::fontColor(int aId) { return mFontColor[aId]; }
const ScenarioData& Data::scenario(int aId) const { return mScenario[aId]; }
const SaveData& Data::saveData(int aNum) const { return mSaveData[aNum]; }


}