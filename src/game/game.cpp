//---------------------------------------------------------------------
// 
//  
// 
//
#include "game.hpp"
#include "DxLib.h"
#include "system/input.hpp"
#include "system/system.hpp"
#include "assets/data.hpp"
#include "system/scene_manager.hpp"
#include "util/util.hpp"

namespace osiv {

//---------------------------------------------------------------------
// 
//  コンストラクタ
// 
//
Game::Game()
    : mScenarioId(0)
    , mTextLength(0)
    , mTextLength1(0)
    , mTextLength2(0)
    , mTextLength3(0)
    , mTextLengthMax(0)
    , mAutoFlag(false)
    , mSkipFlag(false)
    , mHideFlag(false)
    , mFadeFlag(false)
    , mFrame(0)
    , mScenarioFrame(0)
    , mFulOpenFrame(0)
    , mFadeFrame(0)
    , mButtonAuto()
    , mButtonSkip()
    , mButtonLog()
    , mButtonConf()
    , mButtonSave()
    , mButtonLoad()
    , mButtonClose()
{
}

//---------------------------------------------------------------------
// 
//  初期化処理
// 
//
void Game::initialize()
{
    mTextLengthMax = 50;

    mButtonAuto.setPosX(System::ins().windowSizeX() - 130);
    mButtonAuto.setPosY(System::ins().windowSizeY() - 160);
    mButtonAuto.setSize(49, 44);

    mButtonSkip.setPosX(System::ins().windowSizeX() - 130 + 49 + 5);
    mButtonSkip.setPosY(System::ins().windowSizeY() - 160);
    mButtonSkip.setSize(49, 44);

    mButtonLog.setPosX(System::ins().windowSizeX() - 130);
    mButtonLog.setPosY(System::ins().windowSizeY() - 160 + 44 + 5);
    mButtonLog.setSize(49, 44);

    mButtonConf.setPosX(System::ins().windowSizeX() - 130 + 49 + 5);
    mButtonConf.setPosY(System::ins().windowSizeY() - 160 + 44 + 5);
    mButtonConf.setSize(49, 44);

    mButtonSave.setPosX(System::ins().windowSizeX() - 130);
    mButtonSave.setPosY(System::ins().windowSizeY() - 160 + (44 + 5) * 2);
    mButtonSave.setSize(49, 44);

    mButtonLoad.setPosX(System::ins().windowSizeX() - 130 + 49 + 5);
    mButtonLoad.setPosY(System::ins().windowSizeY() - 160 + (44 + 5) * 2);
    mButtonLoad.setSize(49, 44);

    mButtonClose.setPosX(System::ins().windowSizeX() - 180);
    mButtonClose.setPosY(System::ins().windowSizeY() - 180);
    mButtonClose.setSize(25, 25);
}

//---------------------------------------------------------------------
// 
//  更新処理
// 
//
void Game::update()
{
    mFrame++;

    //----- フェードの更新
    if (mFadeFlag) {
        mFadeFrame++;
        
    }

    //----- シナリオの状態更新
    updateScenario();

    //----- キー操作
    keyProcess();

    //----- クリック処理
    clickProcess();
}

//---------------------------------------------------------------------
// 
//  シナリオ状態更新
// 
//
void Game::updateScenario()
{
    //----- ウインドウ非表示中なら状態更新しない
    if (mHideFlag) {
        return;
    }
    //----- フェード中なら更新しない
    if (mFadeFlag) {
        return;
    }

    //----- 次の文字
    nextWord();

    //----- 更新
    mScenarioFrame++;
    if (isFullOpen()) {
        mFulOpenFrame++;
    }
    else {
        //----- スキップ中ならテキストをフルオープン
        if (mSkipFlag) {
            fullOpen();
        }
    }

    //----- オート中で一定時間経ったら次のシナリオ
    if (mAutoFlag && (mFulOpenFrame >= 70)) {
        nextScenario();
    }
    //----- スキップ中なら次のシナリオ
    if (mSkipFlag && (mScenarioFrame >= 5)) {
        nextScenario();
    }
}

//---------------------------------------------------------------------
// 
//  キー操作
// 
//
void Game::keyProcess()
{
    //----- 移動キー
    if (Input::ins().key(KEY_INPUT_UP) || Input::ins().key(KEY_INPUT_W)) {
    }
    if (Input::ins().key(KEY_INPUT_RIGHT) || Input::ins().key(KEY_INPUT_D)) {
    }
    if (Input::ins().key(KEY_INPUT_DOWN) || Input::ins().key(KEY_INPUT_S)) {
    }
    if (Input::ins().key(KEY_INPUT_LEFT) || Input::ins().key(KEY_INPUT_A)) {
    }

}

//---------------------------------------------------------------------
// 
//  クリック操作
// 
//
void Game::clickProcess()
{
    //----- 左クリック押下時
    if (Input::ins().leftClick() == 1) {
        clickProcessLeft();
    }

    //----- 右クリック押下時
    if (Input::ins().rightClick() == 1) {
        clickProcessRight();
    }
}

//---------------------------------------------------------------------
// 
//  左クリックの処理
// 
//
void Game::clickProcessLeft()
{
    //----- フェード中なら更新しない
    if (mFadeFlag) {
        return;
    }
    //----- オート中ならオート解除
    if (mAutoFlag) {
        mAutoFlag = false;
        return;
    }
    //----- スキップ中ならスキップ解除
    if (mSkipFlag) {
        mSkipFlag = false;
        return;
    }
    //----- 画面非表示中なら解除
    if (mHideFlag) {
        mHideFlag = false;
        return;
    }

    //-----
    int posX = Input::ins().pointX();
    int posY = Input::ins().pointY();

    //-----オートボタン
    if (mButtonAuto.isCollision(posX, posY)) {
        mAutoFlag = true;
    }
    //----- スキップボタン
    else if (mButtonSkip.isCollision(posX, posY)) {
        mSkipFlag = true;
    }
    //----- ログボタン
    else if (mButtonLog.isCollision(posX, posY)) {
        SceneManager::ins().change(SceneManager::SCENE_BACKLOG);
    }
    //----- コンフィグボタン
    else if (mButtonConf.isCollision(posX, posY)) {
    }
    //----- セーブボタン
    else if (mButtonSave.isCollision(posX, posY)) {
        SceneManager::ins().change(SceneManager::SCENE_SAVE);
    }
    //----- ロードボタン
    else if (mButtonLoad.isCollision(posX, posY)) {
        SceneManager::ins().change(SceneManager::SCENE_LOAD);
    }
    //----- 閉じるボタン
    else if (mButtonClose.isCollision(posX, posY)) {
        mHideFlag = true;
    }
    else {
        // テキスト表示完了しているなら次シナリオ
        if (isFullOpen()) {
            nextScenario();
        }
        // テキスト表示中ならテキストフルオープン
        else {
            fullOpen();
        }
    }
}

//---------------------------------------------------------------------
// 
//  右クリックの処理
// 
//
void Game::clickProcessRight()
{
    // フェード中なら更新しない
    if (mFadeFlag) {
        return;
    }
    // ウインドウ非表示中なら解除
    if (mHideFlag) {
        mHideFlag = false;
        return;
    }
    // ウインドウ表示中なら非表示
    if (!mHideFlag) {
        mHideFlag = true;
        return;
    }
}


//---------------------------------------------------------------------
// 
//  次の文字へ
// 
//
void Game::nextWord()
{
    // フルーオープンでないなら
    if (!isFullOpen()) {
        mTextLength += Util::isJapaneseCharacter(scenario().text()[mTextLength]);
        // 1行目なら
        if (mTextLength <= mTextLengthMax) {
            mTextLength1 = mTextLength;
        }
        // 2行目なら
        else if (mTextLength <= (mTextLength1 + mTextLengthMax)) {
            mTextLength2 = mTextLength - mTextLength1;
        }
        // 3行目なら
        else {
            mTextLength3 = mTextLength - mTextLength1 - mTextLength2;
        }
    }
}

//---------------------------------------------------------------------
// 
//  テキストをフルオープン
// 
//
void Game::fullOpen()
{
    while (mTextLength < (int)scenarioText().size()) {
        nextWord();
    }
}

//---------------------------------------------------------------------
// 
//  次のシナリオへ
// 
//
void Game::nextScenario(bool aJumpFlag)
{
    if (scenario().fade() != -1 && aJumpFlag == false) {
        //mFadeFlag = true;
        SceneManager::ins().change(SceneManager::SCENE_GAME);
        SceneManager::ins().setParam1(mScenarioId + 1);
        SceneManager::ins().setFadeSpeed(3);
    }
    else {
        mScenarioId++;
        mTextLength = 0;
        mTextLength1 = 0;
        mTextLength2 = 0;
        mTextLength3 = 0;
        mScenarioFrame = 0;
        mFulOpenFrame = 0;
    }
}

//---------------------------------------------------------------------
// 
//  次のシナリオへ
// 
//
bool Game::isFullOpen() const
{
    return (mTextLength >= (int)scenarioText().length());
}

//---------------------------------------------------------------------
// 
//  指定のシナリオにジャンプ
// 
//
void Game::jumpScenario(int aId)
{
    mScenarioId = aId - 1;
    nextScenario(true);
}

//---------------------------------------------------------------------
// 
//  setter
// 
//
void Game::setAutoFlag(bool aFlag) { mAutoFlag = aFlag; }

//---------------------------------------------------------------------
// 
//  getter
// 
//
const ScenarioData& Game::scenario() const { return Data::ins().scenario(mScenarioId); }
//---------------------------------------------------------------------
std::string Game::scenarioText() const { return scenario().text(); }
//---------------------------------------------------------------------
int Game::scenarioId() const { return mScenarioId; }
//---------------------------------------------------------------------
std::string Game::text1() const { return scenarioText().substr(0, mTextLength1); }
//---------------------------------------------------------------------
std::string Game::text2() const { return scenarioText().substr(mTextLength1, mTextLength2); }
//---------------------------------------------------------------------
std::string Game::text3() const { return scenarioText().substr(mTextLength1 + mTextLength2, mTextLength3); }
//---------------------------------------------------------------------
bool Game::autoFlag() const { return mAutoFlag; }
//---------------------------------------------------------------------
bool Game::hideFlag() const { return mHideFlag; }
//---------------------------------------------------------------------
const Button& Game::buttonAuto() const { return mButtonAuto; }
//---------------------------------------------------------------------
const Button& Game::buttonSkip() const { return mButtonSkip; }
//---------------------------------------------------------------------
const Button& Game::buttonLog() const { return mButtonLog; }
//---------------------------------------------------------------------
const Button& Game::buttonConf() const { return mButtonConf; }
//---------------------------------------------------------------------
const Button& Game::buttonSave() const { return mButtonSave; }
//---------------------------------------------------------------------
const Button& Game::buttonLoad() const { return mButtonLoad; }
//---------------------------------------------------------------------
const Button& Game::buttonClose() const { return mButtonClose; }
//---------------------------------------------------------------------
int Game::buttonAutoIndex() const
{
    if (mAutoFlag) {
        return 1;
    }
    if (mSkipFlag) {
        return 2;
    }
    return (mButtonAuto.isCollisionMouse() ? 1 : 0);
}
//---------------------------------------------------------------------
int Game::buttonSkipIndex() const
{
    if (mAutoFlag) {
        return 2;
    }
    if (mSkipFlag) {
        return 1;
    }
    return (mButtonSkip.isCollisionMouse() ? 1 : 0);
}
//---------------------------------------------------------------------
int Game::buttonLogIndex() const
{
    if (mAutoFlag) {
        return 2;
    }
    if (mSkipFlag) {
        return 2;
    }
    return (mButtonLog.isCollisionMouse() ? 1 : 0);
}
//---------------------------------------------------------------------
int Game::buttonConfIndex() const
{
    if (mAutoFlag) {
        return 2;
    }
    if (mSkipFlag) {
        return 2;
    }
    return (mButtonConf.isCollisionMouse() ? 1 : 0);
}
//---------------------------------------------------------------------
int Game::buttonSaveIndex() const
{
    if (mAutoFlag) {
        return 2;
    }
    if (mSkipFlag) {
        return 2;
    }
    return (mButtonSave.isCollisionMouse() ? 1 : 0);
}
//---------------------------------------------------------------------
int Game::buttonLoadIndex() const
{
    if (mAutoFlag) {
        return 2;
    }
    if (mSkipFlag) {
        return 2;
    }
    return (mButtonLoad.isCollisionMouse() ? 1 : 0);
}
//---------------------------------------------------------------------
int Game::buttonCloseIndex() const
{
    if (mAutoFlag) {
        return 2;
    }
    if (mSkipFlag) {
        return 2;
    }
    return (mButtonClose.isCollisionMouse() ? 1 : 0);
}
//---------------------------------------------------------------------
int Game::frame() const { return mFrame; }
//---------------------------------------------------------------------


} // namespace