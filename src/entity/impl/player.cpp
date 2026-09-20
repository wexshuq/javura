//
// Created by wexshuq on 16.09.2026.
//

#include "player.h"

#include "raylib.h"
#include "rlgl.h"
#include "../../renderer/renderer.h"
#include "../../utils/raysync.h"

void Player::Draw(const World &world) const {

    rlPushMatrix();
    rlMultMatrixf(getTransformation().getMatrix().data);
    Renderer::DrawCube3D({1,0,0,1}); // normalize test

    rlPopMatrix();
}

void Player::Update(World &world, PlayerInputData data) {
    if (data.forward) {
        this->getPosition().z += 0.4f;
    }else if (data.back) {
        this->getPosition().z -= 0.4f;
    }
    if (data.left) {
        this->getPosition().x -= 0.4f;
    }else if (data.right) {
        this->getPosition().x += 0.4f;
    }
}

