//
// Created by wexshuq on 13.09.2026.
//
#pragma once

#include <raylib.h>
#include "../math/vec3.h"

class MainCamera
{
public:
    void Update();

    [[nodiscard]] const Camera3D& GetRayCamera() const
    {
        return rayCamera;
    }

    Vec3 position;
    Vec3 target;
    Vec3 up;


    float fovy=0;
    int projection = CAMERA_PERSPECTIVE;
    int mode = CAMERA_FREE;

private:
    Camera3D rayCamera{};
};
