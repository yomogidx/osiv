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
    addScenario("名前", "本プロジェクトは、アドベンチャーゲーム制作プロジェクトの一環として開発されたデモ版です。", 1);
    addScenario("名前", "シナリオデータの読込み、セーブ、ロード、バックログ、オート、スキップの基本機能を有します。", 1);
    addScenario("名前", "シーンがチェンジします。", 1);
    addScenarioFade(0);
    addScenario("", "シーンがチェンジしました。", 2, 0);
    addScenario("名前", "「表情1の設定」", 2, 1);
    addScenario("名前", "「表情2の設定」", 2, 2);
    addScenario("名前", "「表情3の設定」", 2, 2);
    addScenario("名前", "本文章はテスト用のテキストです。１", 2);
    addScenario("名前", "本文章はテスト用のテキストです。２", 2);
    addScenario("名前", "本文章はテスト用のテキストです。３", 2);
    addScenario("名前", "本文章はテスト用のテキストです。４", 2);
    addScenario("名前", "本文章はテスト用のテキストです。５", 2);
    addScenario("名前", "本文章はテスト用のテキストです。６", 2);
    addScenario("名前", "本文章はテスト用のテキストです。７", 2);
    addScenario("名前", "本文章はテスト用のテキストです。８", 2);
    addScenario("名前", "本文章はテスト用のテキストです。９", 2);
    addScenario("名前", "本文章はテスト用のテキストです。１０", 2);
    addScenario("名前", "本文章はテスト用のテキストです。１１", 2);
    addScenario("名前", "本文章はテスト用のテキストです。１２", 2);
    addScenarioFade(0);
    addScenario("名前", "本文章はテスト用のテキストです。１３", 2);
    addScenario("名前", "本文章はテスト用のテキストです。１４", 2);
    addScenario("名前", "本文章はテスト用のテキストです。１５", 2);
    addScenario("名前", "本文章はテスト用のテキストです。１６", 2);
    addScenario("名前", "本文章はテスト用のテキストです。１７", 2);
    addScenario("名前", "本文章はテスト用のテキストです。１８", 2);
    addScenario("名前", "本文章はテスト用のテキストです。１９", 2);
    addScenario("名前", "本文章はテスト用のテキストです。２０", 2);
    addScenario("名前", "本文章はテスト用のテキストです。２１", 2);
    addScenario("名前", "本文章はテスト用のテキストです。２２", 2);
    addScenario("名前", "本文章はテスト用のテキストです。２３", 2);
    addScenario("名前", "本文章はテスト用のテキストです。２４", 2);
    addScenario("名前", "本文章はテスト用のテキストです。２５", 2);
    addScenario("名前", "本文章はテスト用のテキストです。２６", 2);
    addScenario("名前", "本文章はテスト用のテキストです。２７", 2);
    addScenario("名前", "本文章はテスト用のテキストです。２８", 2);
    addScenario("名前", "本文章はテスト用のテキストです。２９", 2);
    addScenario("名前", "本文章はテスト用のテキストです。３０", 2);
    addScenario("名前", "本文章はテスト用のテキストです。３１", 2);
    addScenario("名前", "本文章はテスト用のテキストです。３２", 2);
    addScenario("名前", "本文章はテスト用のテキストです。３３", 2);
    addScenario("名前", "本文章はテスト用のテキストです。３４", 2);
    addScenario("名前", "本文章はテスト用のテキストです。３５", 2);
    addScenario("名前", "本文章はテスト用のテキストです。３６", 2);
    addScenario("名前", "本文章はテスト用のテキストです。３７", 2);
    addScenario("名前", "本文章はテスト用のテキストです。３８", 2);
    addScenario("名前", "本文章はテスト用のテキストです。３９", 2);
    addScenario("名前", "本文章はテスト用のテキストです。４０", 2);
    addScenario("名前", "本文章はテスト用のテキストです。４１", 2);
    addScenario("名前", "本文章はテスト用のテキストです。４２", 2);
    addScenario("名前", "本文章はテスト用のテキストです。４３", 2);
    addScenario("名前", "本文章はテスト用のテキストです。４４", 2);
    addScenario("名前", "本文章はテスト用のテキストです。４５", 2);
    addScenario("名前", "本文章はテスト用のテキストです。４６", 2);
    addScenario("名前", "本文章はテスト用のテキストです。４７", 2);
    addScenario("名前", "本文章はテスト用のテキストです。４８", 2);
    addScenario("名前", "本文章はテスト用のテキストです。４９", 2);
    addScenario("名前", "本文章はテスト用のテキストです。５０", 2);
    addScenario("名前", "本文章はテスト用のテキストです。５１", 2);
    addScenario("名前", "本文章はテスト用のテキストです。５２", 2);
    addScenario("名前", "本文章はテスト用のテキストです。５３", 2);
    addScenario("名前", "本文章はテスト用のテキストです。５４", 2);
    addScenario("名前", "本文章はテスト用のテキストです。５５", 2);
    addScenario("名前", "本文章はテスト用のテキストです。５６", 2);
    addScenario("名前", "本文章はテスト用のテキストです。５７", 2);
    addScenario("名前", "本文章はテスト用のテキストです。５８", 2);
    addScenario("名前", "本文章はテスト用のテキストです。５９", 2);
    addScenario("名前", "本文章はテスト用のテキストです。６０", 2);
    addScenario("名前", "本文章はテスト用のテキストです。６１", 2);
    addScenario("名前", "本文章はテスト用のテキストです。６２", 2);
    addScenario("名前", "本文章はテスト用のテキストです。６３", 2);
    addScenario("名前", "本文章はテスト用のテキストです。６４", 2);
    addScenario("名前", "本文章はテスト用のテキストです。６５", 2);
    addScenario("名前", "本文章はテスト用のテキストです。６６", 2);
    addScenario("名前", "本文章はテスト用のテキストです。６７", 2);
    addScenario("名前", "本文章はテスト用のテキストです。６８", 2);
    addScenario("名前", "本文章はテスト用のテキストです。６９", 2);
    addScenario("名前", "本文章はテスト用のテキストです。７０", 2);
    addScenario("名前", "本文章はテスト用のテキストです。７１", 2);
    addScenario("名前", "本文章はテスト用のテキストです。７２", 2);
    addScenario("名前", "本文章はテスト用のテキストです。７３", 2);
    addScenario("名前", "本文章はテスト用のテキストです。７４", 2);
    addScenario("名前", "本文章はテスト用のテキストです。７５", 2);
    addScenario("名前", "本文章はテスト用のテキストです。７６", 2);
    addScenario("名前", "本文章はテスト用のテキストです。７７", 2);
    addScenario("名前", "本文章はテスト用のテキストです。７８", 2);
    addScenario("名前", "本文章はテスト用のテキストです。７９", 2);
    addScenario("名前", "本文章はテスト用のテキストです。８０", 2);
    addScenario("名前", "本文章はテスト用のテキストです。８１", 2);
    addScenario("名前", "本文章はテスト用のテキストです。８２", 2);
    addScenario("名前", "本文章はテスト用のテキストです。８３", 2);
    addScenario("名前", "本文章はテスト用のテキストです。８４", 2);
    addScenario("名前", "本文章はテスト用のテキストです。８５", 2);
    addScenario("名前", "本文章はテスト用のテキストです。８６", 2);
    addScenario("名前", "本文章はテスト用のテキストです。８７", 2);
    addScenario("名前", "本文章はテスト用のテキストです。８８", 2);
    addScenario("名前", "本文章はテスト用のテキストです。８９", 2);
    addScenario("名前", "本文章はテスト用のテキストです。９０", 2);
    addScenario("名前", "本文章はテスト用のテキストです。９１", 2);
    addScenario("名前", "本文章はテスト用のテキストです。９２", 2);
    addScenario("名前", "本文章はテスト用のテキストです。９３", 2);
    addScenario("名前", "本文章はテスト用のテキストです。９４", 2);
    addScenario("名前", "本文章はテスト用のテキストです。９５", 2);
    addScenario("名前", "本文章はテスト用のテキストです。９６", 2);
    addScenario("名前", "本文章はテスト用のテキストです。９７", 2);
    addScenario("名前", "本文章はテスト用のテキストです。９８", 2);
    addScenario("名前", "本文章はテスト用のテキストです。９９", 2);
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