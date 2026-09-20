//
// Created by wexshuq on 13.09.2026.
//

#include "camera.h"
#include "../utils/raysync.h"

void MainCamera::Update(Player& player)
{
    // RayLib Synchronization
    //position = player.getPosition()-Vec3(3,-3,0);
    //target = player.getPosition();

    rayCamera.position = RaySync::ToRay(position);
    rayCamera.target = RaySync::ToRay(target);
    rayCamera.up = RaySync::ToRay(up);

    rayCamera.fovy = fovy;
    rayCamera.projection = projection;

    UpdateCamera(&rayCamera, mode);

    position = RaySync::FromRay(rayCamera.position);
    target = RaySync::FromRay(rayCamera.target);
    up = RaySync::FromRay(rayCamera.up);
}