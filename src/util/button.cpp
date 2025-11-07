//---------------------------------------------------------------------
// 
//  
// 
//
#include "button.hpp"
#include "system/input.hpp"

namespace osiv {

//---------------------------------------------------------------------
// 
//  コンストラクタ
// 
//
Button::Button()
    : mPosX(0)
    , mPosY(0)
    , mSizeX(0)
    , mSizeY(0)
{
}

//---------------------------------------------------------------------
// 
//  当たり判定
// 
//
bool Button::isCollision(int aX, int aY) const
{
    if (aX < mPosX) { return false; }
    if (aX > (mPosX + mSizeX)) { return false; }
    if (aY < mPosY) { return false; }
    if (aY > (mPosY + mSizeY)) { return false; }
    return true;
}

//---------------------------------------------------------------------
// 
//  マウスカーソルとの当たり判定
// 
//
bool Button::isCollisionMouse() const
{
    return isCollision(
        Input::ins().pointX(),
        Input::ins().pointY());
}

//---------------------------------------------------------------------
// 
//  画像のインデックス取得
// 
//
int Button::imageIndex() const
{
    return (isCollisionMouse() ? 1 : 0);
}

//---------------------------------------------------------------------
// 
//  setter
// 
//
void Button::setPos(int aX, int aY) { mPosX = aX; mPosY = aY; }
void Button::setPosX(int aX) { mPosX = aX; }
void Button::setPosY(int aY) { mPosY = aY; }
void Button::setSize(int aX, int aY) { mSizeX = aX; mSizeY = aY; }
void Button::setSizeX(int aX) { mSizeX = aX; }
void Button::setSizeY(int aY) { mSizeY = aY; }

//---------------------------------------------------------------------
// 
//  getter
// 
//
int Button::posX() const { return mPosX; }
int Button::posY() const { return mPosY; }
int Button::sizeX() const { return mSizeX; }
int Button::sizeY() const { return mSizeY; }

} // namespace