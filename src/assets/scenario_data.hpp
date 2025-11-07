//---------------------------------------------------------------------
// 
//  
// 
//
#pragma once
#include <vector>
#include <string>

namespace osiv {
//---------------------------------------------------------------------
// 
//  
// 
//
class ScenarioData {
public:
    /// コンストラクタ
    ScenarioData();

    /// setter
    void setId(int aId);
    void setName(std::string aName);
    void setText(std::string aText);
    void setBack(int aId);
    void setChara1Id(int aId);
    void setChara1Face(int aId);
    void setChara2Id(int aId);
    void setChara2Face(int aId);
    void setChara3Id(int aId);
    void setChara3Face(int aId);
    void setFade(int aFadeKind);

    /// getter
    int id() const;
    std::string name() const;
    std::string text() const;
    int textLength() const;
    std::string text1() const;
    std::string text2() const;
    std::string text3() const;
    std::string text1small() const;
    std::string text2small() const;
    int back() const;
    int chara1Id() const;
    int chara2Id() const;
    int chara3Id() const;
    int chara1Face() const;
    int chara2Face() const;
    int chara3Face() const;
    int fade() const;

private:
    int mId;           // シナリオID
    std::string mName; // 名前
    std::string mText; // テキスト
    std::string mText1; // テキスト
    std::string mText2; // テキスト
    std::string mText3; // テキスト
    std::string mText1small; // テキスト
    std::string mText2small; // テキスト
    int mBack;          // 背景画像
    int mChara1Id;      // キャラ1
    int mChara2Id;      // キャラ2
    int mChara3Id;      // キャラ3
    int mChara1Face;    // キャラ1
    int mChara2Face;    // キャラ1
    int mChara3Face;    // キャラ1
    int mFade;          // フェード
};

}