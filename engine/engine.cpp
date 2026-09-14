//
// Created by wexshuq on 13.09.2026.
//
#include "engine.h"
#include <raylib.h>

#include "rlgl.h"
#include "../math/matrix4x4.h"

void Engine::Init()
{
    SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT | FLAG_MSAA_4X_HINT | FLAG_WINDOW_UNFOCUSED );
    InitWindow(1980, 1080, "My Game");
    DisableCursor();
    SetExitKey(-1);

    camera.position = Vec3(0, 10, 10);
    camera.target = Vec3(0, 0, 0);
    camera.up = Vec3(0, 1, 0);
    camera.fovy = 45;
    camera.projection = 0;
    camera.mode =1;
}

void Engine::ShutDown()
{
    CloseWindow();
}


void Engine::Run()
{
    Init();

    float angle = 0.0f;
    while (!WindowShouldClose())
    {
        angle += 360 * GetFrameTime();
        // Game Loop
        camera.Update();
        BeginDrawing();
        ClearBackground(RAYWHITE);

        Matrix4x4 matrix = Matrix4x4::Identity();

        matrix.Scale({1,1,1});
        matrix.Translate({2,3,2});
        DrawFPS(10,10);
        DrawText("Hello world", 100, 100, 30, BLACK);
        BeginMode3D(camera.GetRayCamera());
        rlPushMatrix();
        rlMultMatrixf(matrix.data);
        DrawCube({0,0,0},1,1,1,RED);
        DrawCubeWires({0,0,0},1,1,1,BLACK);
        rlPopMatrix();
        DrawGrid(20,1);
        EndMode3D();
        EndDrawing();
    }

    ShutDown();
}
