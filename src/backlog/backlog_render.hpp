//---------------------------------------------------------------------
// 
//  
// 
//
#pragma once
#include "backlog/backlog.hpp"

namespace osiv {

//---------------------------------------------------------------------
// 
//  
// 
//
class BacklogRender {
public:
    /// コンストラクタ
    BacklogRender();

    /// 描画処理
    void render(const Backlog& aBacklog) const;

    /// setter

private:
};

} // namespace 