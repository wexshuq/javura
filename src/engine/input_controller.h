//
// Created by wexshuq on 16.09.2026.
//

#pragma once
#include "../math/vec2.h"

struct PlayerInputData {
    bool forward{},
    back{},
    left{},
    right{},
    jump{},
    sneak{};

    Vec2 mouseDelta;
};

class InputController {
public:
    static PlayerInputData FetchData();

};