//---------------------------------------------------------------------
// 
//  FpsManager
// 
//
#pragma once
#include "DxLib.h"

namespace osiv {

//---------------------------------------------------------------------
// 
//  
// 
//
class FpsManager {
public:
    static const int FPS = 60;

    FpsManager();
    void update();
    void wait();

    double fps() const;

private:
    static const int N = 60;   // Œv‘ª‚ÌƒTƒ“ƒvƒ‹”
    int mStartTime;
    int mCounter;
    double mFps;
};

}