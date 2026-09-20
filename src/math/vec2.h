//
// Created by wexshuq on 16.09.2026.
//

#pragma once
#include <cmath>


class Vec2 {
public:
    float x, y;
    Vec2() : x(0), y(0) {}
    Vec2(const float _x, const float _y) : x(_x), y(_y) {}

    Vec2 operator+(const Vec2& other) const {
        return {x + other.x, y + other.y};
    }
    Vec2 operator-(const Vec2& other) const {
        return {x - other.x, y - other.y};
    }
    float length() const { return std::hypot(x,y); }
    Vec2 normal() const {
        const float len = length();
        if (len == 0.0f) return {0.0f, 0.0f};
        return {x / len, y / len};
    };
    float dot(const Vec2& b) const {
        return x * b.x + y * b.y;
    }

};

