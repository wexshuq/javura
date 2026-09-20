//
// Created by wexshuq on 13.09.2026.
//
#pragma once
#include "input_controller.h"
#include "../map/world.h"
#include "camera.h"

class Engine
{
public:
    void Run();


    [[nodiscard]] const MainCamera& getCamera() const {
        return camera;
    }

    [[nodiscard]] const World& getWorld() const {
        return world;
    }

private:
    void Init();
    void ShutDown();

    MainCamera camera;
    World world;
    InputController inputController;
};