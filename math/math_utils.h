//
// Created by wexshuq on 14.09.2026.
//

#pragma once

namespace Math
{
    constexpr float ToRadians(const float degrees)
    {
        return degrees * PI / 180.0f;
    }

    constexpr float ToDegrees(const float radians)
    {
        return radians * 180.0f / PI;
    }
}