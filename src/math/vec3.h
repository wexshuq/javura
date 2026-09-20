//
// Created by wexshuq on 13.09.2026.
//

#pragma once
#include <cmath>

class Vec3 {
public:
    float x, y, z;
    Vec3() : x(0), y(0), z(0) {}
    Vec3(const float _x, const float _y, const float _z) : x(_x), y(_y), z(_z) {}

    Vec3 operator+(const Vec3& other) const {
        return {x + other.x, y + other.y, z + other.z};
    }
    Vec3 operator-(const Vec3& other) const {
        return {x - other.x, y - other.y, z - other.z};
    }
    float length() const { return std::sqrt(x * x + y * y + z * z); }
    Vec3 normal() const {
            const float len = length();
            if (len == 0.0f) return { 0.0f, 0.0f, 0.0f };
            return {x / len, y / len, z / len
        };
    }
    float dot(const Vec3& b) const {
        return x * b.x + y * b.y + z * b.z;
    }

};

