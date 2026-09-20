//
// Created by wexshuq on 13.09.2026.
//
#pragma once

#pragma once

#include <algorithm>
#include <raylib.h>
#include <cmath>

#include "JavColor.h"
#include "../math/vec3.h"
#include "../math/vec2.h"

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

    inline Vec2 FromRay(const Vector2& v)
    {
        return {v.x, v.y};
    }

    inline JavColor FromRay(const Color& c, const bool normalize)
    {
        JavColor output = {static_cast<float>(c.r), static_cast<float>(c.g), static_cast<float>(c.b),static_cast<float>(c.a)};
        if (normalize) {
            output.r = output.r / 255.0f;
            output.g = output.g / 255.0f;
            output.b = output.b / 255.0f;
            output.a = output.a / 255.0f;
        }

        return output;
    }

    inline Color ToRay(const JavColor& c, const bool normalize)
    {
        const float factor = normalize ? 255.0f : 1.0f;

        return Color{
            static_cast<unsigned char>(std::clamp(std::round(c.r * factor), 0.0f, 255.0f)),
            static_cast<unsigned char>(std::clamp(std::round(c.g * factor), 0.0f, 255.0f)),
            static_cast<unsigned char>(std::clamp(std::round(c.b * factor), 0.0f, 255.0f)),
            static_cast<unsigned char>(std::clamp(std::round(c.a * factor), 0.0f, 255.0f))
        };
    }
}