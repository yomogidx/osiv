//---------------------------------------------------------------------
// 
//  
// 
//
#pragma once
#include "saveload/saveload.hpp"

namespace osiv {

//---------------------------------------------------------------------
// 
//  
// 
//
class SaveloadRender {
public:
    /// コンストラクタ
    SaveloadRender();

    /// 描画
    void render(const Saveload& aSaveload) const;

private:
};

} // namespace 