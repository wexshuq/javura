//
// Created by wexshuq on 14.09.2026.
//

#pragma once

#include "vec3.h"
#include <cmath>

#include "math_utils.h"


class Matrix4x4 {

public:
    float data[16];

    const float& At(const int row, const int column) const
    {
        return data[column * 4 + row];
    }
    float& At(const int row, const int column)
    {
        return data[column * 4 + row];
    }

    static Matrix4x4 Identity() {
        constexpr Matrix4x4 result {
            1,0,0,0,
            0,1,0,0,
            0,0,1,0,
            0,0,0,1
        };
        return result;
    }

    Matrix4x4 operator*(const Matrix4x4& other) const {
        Matrix4x4 result{};

        for (int row = 0; row < 4; row++) {
            for (int column = 0; column < 4; column++) {
                float sum = 0.0f;
                for (int i = 0; i < 4; i++) {
                    sum += At(row, i) * other.At(i, column);
                }
                result.At(row, column) = sum;
            }
        }
        return result;
    }

    Matrix4x4& Scale(const Vec3 scale) {
        Matrix4x4 result = Identity();
        result.At(0, 0) = scale.x;
        result.At(1, 1) = scale.y;
        result.At(2, 2) = scale.z;

        *this = result * *this;
        return *this;
    }

    Matrix4x4& Translate(const Vec3& translation)
    {
        Matrix4x4 result = Identity();

        result.At(0, 3) = translation.x;
        result.At(1, 3) = translation.y;
        result.At(2, 3) = translation.z;

        *this = result * *this;
        return *this;
    }

    Matrix4x4& RotateY(const float angle)
    {
        const float radians = Math::ToRadians(angle);

        const float c = std::cos(radians);
        const float s = std::sin(radians);

        const Matrix4x4 rotation{
            c,0,s,0,
            0,1,0,0,
            -s,0,c,0,
            0,0,0,1
        };

        *this = rotation * *this;

        return *this;
    }
    Matrix4x4& RotateX(const float angle)
    {
        const float radians = Math::ToRadians(angle);

        const float c = std::cos(radians);
        const float s = std::sin(radians);

        const Matrix4x4 rotation{
            1,0,0,0,
            0,c,-s,0,
            0,s,c,0,
            0,0,0,1
        };

        *this = rotation * *this;

        return *this;
    }

    Matrix4x4& RotateZ(const float angle)
    {
        const float radians = Math::ToRadians(angle);

        const float c = std::cos(radians);
        const float s = std::sin(radians);

        const Matrix4x4 rotation{
            c,-s,0,0,
            s,c,0,0,
            0,0,1,0,
            0,0,0,1
        };

        *this = rotation * *this;

        return *this;
    }
};
