//
// Created by wexshuq on 13.09.2026.
//
#include "engine.h"
#include <raylib.h>
#include <algorithm>
#include <iostream>

#include "rlgl.h"
#include "../math/matrix4x4.h"
#include "../math/transformation.h"
#include "../renderer/renderer.h"

void Engine::Init()
{
    SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT | FLAG_MSAA_4X_HINT | FLAG_WINDOW_UNFOCUSED );
    InitWindow(1980, 1080, "My Game");
    DisableCursor();
    SetExitKey(KEY_NULL);

    camera.position = Vec3(0, 10, 10);
    camera.target = Vec3(0, 0, 0);
    camera.up = Vec3(0, 1, 0);
    world.Init();
}

void Engine::ShutDown()
{
    CloseWindow();
}


void Engine::Run()
{
    constexpr float fixedDt = 1.0f / 60.0f;

    float accumulator = 0.0f;
    Init();

    while (!WindowShouldClose())
    {
        if (world.initialized) {
            float frameTime = GetFrameTime();
            frameTime = std::min(frameTime, 0.25f);
            accumulator += frameTime;

            PlayerInputData inputData = InputController::FetchData();

            while (accumulator >= fixedDt) {
                world.Update(inputData, fixedDt);
                accumulator -= fixedDt;
            }

            Renderer::BeginRender();
            ClearBackground(RAYWHITE);
            camera.Update(world.mainPlayer);
            Renderer::BeginRender3D(camera);
            world.Render(camera);
            Renderer::EndRender3D();
            Renderer::EndRender();

        }
    }

    ShutDown();
}
