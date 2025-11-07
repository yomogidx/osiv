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
class AssetsManager {
public:
    static AssetsManager& ins();
    void load();
private:
    AssetsManager();
};

}