//
// Created by wexshuq on 16.09.2026.
//

#include "input_controller.h"

#include "raylib.h"
#include "../utils/raysync.h"


PlayerInputData InputController::FetchData() {
    PlayerInputData data;

    if (IsKeyDown(KEY_T)) data.forward = true;
    if (IsKeyDown(KEY_G)) data.back = true;
    if (IsKeyDown(KEY_H)) data.right = true;
    if (IsKeyDown(KEY_F)) data.left = true;

    if (IsKeyDown(KEY_SPACE)) data.jump = false;
    if (IsKeyDown(KEY_LEFT_CONTROL)) data.sneak = false;

    data.mouseDelta = RaySync::FromRay(GetMouseDelta());

    return data;
}
