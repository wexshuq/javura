//
// Created by wexshuq on 15.09.2026.
//

#include "world.h"

#include "raylib.h"
#include "rlgl.h"
#include "../engine/camera.h"
#include "../renderer/renderer.h"

void World::Init() {
    this->transformation.pos = center;
    this->transformation.scale = {size, 1, size};
    mainPlayer.getPosition() = {5,9,5};
    initialized = true;
}

void World::Render(const MainCamera& camera) const {
    if (!initialized) return;
    rlPushMatrix();
    rlMultMatrixf(transformation.getMatrix().data);
    Renderer::DrawCube3D({0,255,0,255});
    Renderer::DrawCube3DWires({1,1,1,255});
    rlPopMatrix();

    for (const auto& obj : objects) {
        if (!obj) continue;

        rlPushMatrix();
        rlMultMatrixf(obj->transformation.getMatrix().data);

        Renderer::DrawCube3D(obj->color);
        Renderer::DrawCube3DWires({1,1,1,255});
        rlPopMatrix();
    }
    mainPlayer.Draw(*this);
    DrawGrid(20,1);
}

void World::Update(PlayerInputData &pid, float deltaTime) {

    mainPlayer.Update(*this, pid);

}
