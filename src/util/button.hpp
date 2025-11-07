//---------------------------------------------------------------------
// 
//  
// 
//
#pragma once

namespace osiv {
//---------------------------------------------------------------------
// 
//  
// 
//
class Button {
public:
    /// コンストラクタ
    Button();

    /// 当たり判定
    bool isCollision(int aX, int aY) const;

    /// マウスカーソルとの当たり判定
    bool isCollisionMouse() const;

    /// 画像のインデックス取得
    int imageIndex() const;

    /// setter
    void setPos(int aX, int aY);
    void setPosX(int aX);
    void setPosY(int aY);
    void setSize(int aX, int aY);
    void setSizeX(int aX);
    void setSizeY(int aY);

    /// getter
    int posX() const;
    int posY() const;
    int sizeX() const;
    int sizeY() const;

private:
    int mPosX;    // 座標X
    int mPosY;    // 座標Y
    int mSizeX;   // 大きさX
    int mSizeY;   // 大きさY
};

}