//
// Created by wexshuq on 16.09.2026.
//

#pragma once
#include "../entity.h"
#include "../../engine/input_controller.h"

class Player : public Entity {
public:
    Player() {
        setSize({0.6f,1.5f,0.6f});
    }
    void Draw(const World &world) const override;
    void Update(World &world, PlayerInputData data);
};


