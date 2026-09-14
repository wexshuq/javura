//
// Created by wexshuq on 13.09.2026.
//
#pragma once
#include "../renderer/camera.h"


enum class ThreadType
{
    Game,
    Render
};

class Engine
{
public:
    void Run();

private:
    void Init();
    void ShutDown();

    MainCamera camera;
};
