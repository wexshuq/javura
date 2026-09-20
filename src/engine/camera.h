//
// Created by wexshuq on 13.09.2026.
//
#pragma once

#include <raylib.h>

#include "../entity/impl/player.h"
#include "../math/vec3.h"

class MainCamera
{
public:
    enum class TargetType
    {
        Player,
        Other
    };

    void Update(Player& player);

    [[nodiscard]] const Camera3D& GetRayCamera() const
    {
        return rayCamera;
    }

    TargetType currentCameraTarget = TargetType::Player;

    Vec3 position;
    Vec3 target;
    Vec3 up;

    float fovy = 45.0f;
    int projection = CAMERA_PERSPECTIVE;
    int mode = CAMERA_FREE;

private:
    Camera3D rayCamera{};
};