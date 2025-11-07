//---------------------------------------------------------------------
// 
//  
// 
//
#pragma once
#include "game/Game.hpp"

namespace osiv {

//---------------------------------------------------------------------
// 
//  
// 
//
class GameRender {
public:
    GameRender();
    void render(const Game& aGame) const;

private:
    void renderBack(const Game& aGame) const;
    void renderChara(const Game& aGame) const;
    void renderTextwindow(const Game& aGame) const;
};

} // namespace 