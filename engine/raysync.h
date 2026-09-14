//
// Created by wexshuq on 13.09.2026.
//
#pragma once

#pragma once

#include <raylib.h>
#include "../math/vec3.h"

namespace RaySync
{
    inline Vector3 ToRay(const Vec3& v)
    {
        return Vector3{v.x, v.y, v.z};
    }

    inline Vec3 FromRay(const Vector3& v)
    {
        return {v.x, v.y, v.z};
    }
}