//
// Created by wexshuq on 14.09.2026.
//

#pragma once

namespace Math
{
    constexpr float PI_NUM = 3.14159265358979323846f;

    constexpr float ToRadians(const float degrees)
    {
        return degrees * PI_NUM / 180.0f;
    }

    constexpr float ToDegrees(const float radians)
    {
        return radians * 180.0f / PI_NUM;
    }
}
